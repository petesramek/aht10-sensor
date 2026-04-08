#include <aht10/address.h>
#include <aht10/sensor.h>
#include <aht10/temperature.h>
#include <aht10/result.h>

#include <stdexcept>
#include <memory>
#include <iostream>
#include <cstddef>
#include <string>

/// <summary>
/// Waits for the sensor to reach a specified status, polling at intervals and up to a maximum number of iterations.
/// </summary>
/// <param name="expected">
/// The status flag to wait for.
/// </param>
/// <param name="maxIterations">
/// The maximum number of polling attempts before giving up.
/// </param>
/// <param name="waitInterval">
/// The time to wait (in nanoseconds) between polling attempts.
/// </param>
/// <returns>
/// True if the expected status is reached within the allowed iterations; otherwise, false.
/// </returns>
bool Aht10::Sensor::waitForStatus(Status expected, int maxIterations, long waitInterval) const {
	const struct timespec ts = { 0, waitInterval };

	while (maxIterations > 0 && (getStatus() & Status::Busy)) {
		nanosleep(&ts, NULL);
		maxIterations--;
	}

	const Status current = getStatus();

	if (expected == Status::Ready) {
		return !(current & Status::Busy);
	}

	if (!(current & expected)) {
		return false;
	}

	return true;
}

/// <summary>
/// Constructs a Sensor object for the Aht10 device using the specified I2C device path and address selection.
/// </summary>
/// <param name="device">
/// The path to the I2C device (must start with '/dev/i2c-').
/// </param>
/// <param name="useAlternativeAddress">
/// If true, use the alternative I2C address; otherwise, use the default address.
/// </param>
Aht10::Sensor::Sensor(std::string device, bool useAlternativeAddress) {
	if (device.empty()) {
		throw std::invalid_argument("Device name cannot be empty.");
	}

	if (device.rfind("/dev/i2c-", 0) != 0) {
		throw std::invalid_argument("Device name must start with '/dev/i2c-'");
	}

	m_fd = -1;
	m_device = device;
	m_address = useAlternativeAddress ? Address::ALTERNATIVE : Address::DEFAULT;
	m_current_measurement = nullptr;
};

/// <summary>
/// Initializes the Aht10 sensor by opening the I2C device and optionally performing calibration.
/// </summary>
/// <param name="calibrate">
/// If true, performs sensor calibration after initialization.
/// </param>
/// <returns>
/// Returns true if the sensor is successfully initialized (and calibrated if requested); otherwise, throws an exception on failure.
/// </returns>
bool Aht10::Sensor::initialize(bool calibrate) {
	std::cout << "Device opening..." << std::endl;

	if (m_fd >= 0) {
		close(m_fd);
		m_fd = -1;
	}

	m_fd = open(m_device.c_str(), O_RDWR);

	if (m_fd < 0) {
		std::cerr << "Could not open the I2C device: " << strerror(errno) << std::endl;
		throw std::runtime_error("I2C device open failed.");
	}
	if (ioctl(m_fd, I2C_SLAVE, m_address) < 0) {
		std::cerr << "Could not set I2C device address: " << strerror(errno) << std::endl;
		close(m_fd);
		m_fd = -1;
		throw std::runtime_error("I2C address set failed.");
	}

	// Wait for the sensor to power on per the AHT10 datasheet (>= 40 ms)
	const struct timespec power_on_delay = { 0, 40000000L };
	nanosleep(&power_on_delay, NULL);

	std::cout << "Device opened..." << std::endl;

	if (calibrate) {
		return Aht10::Sensor::calibrate();
	}

	return true;
}

/// <summary>
/// Performs a calibration procedure on the Aht10 sensor.
/// </summary>
/// <returns>
/// True if the calibration was successful; false otherwise.
/// </returns>
bool Aht10::Sensor::calibrate() {
	std::cout << "Calibration starting..." << std::endl;

	m_write_buffer[0] = Command::Initialize;
	m_write_buffer[1] = Command::Calibrate;
	m_write_buffer[2] = Command::Empty;

	if (write(m_fd, m_write_buffer, 3) != 3 || !Aht10::Sensor::waitForStatus(Status::Calibrated)) {
		std::cerr << "Calibration failed..." << std::endl;
		return false;
	}

	std::cout << "Calibration finished..." << std::endl;
	return true;
}

/// <summary>
/// Performs a measurement using the Aht10 sensor, reading temperature and humidity data and storing the result.
/// </summary>
/// <returns>
/// True if the measurement and data read were successful; false otherwise.
/// </returns>
bool Aht10::Sensor::measure() {
	std::cout << "Measurement starting..." << std::endl;

	m_write_buffer[0] = Command::Measure;
	m_write_buffer[1] = Command::Read;
	m_write_buffer[2] = Command::Empty;

	if (write(m_fd, m_write_buffer, 3) != 3 || !Aht10::Sensor::waitForStatus(Status::Ready)) {
		std::cerr << "Measurement failed..." << std::endl;
		return false;
	}

	std::cout << "Read starting..." << std::endl;

	if (read(m_fd, m_read_buffer, 6) != 6 || (m_read_buffer[0] & Status::Busy)) {
		std::cerr << "Read failed..." << std::endl;
		return false;
	}

	double humidity = ((m_read_buffer[1] << 12) | (m_read_buffer[2] << 4) | (m_read_buffer[3] >> 4));
	double temperature = (((m_read_buffer[3] & 0x0F) << 16) | (m_read_buffer[4] << 8) | m_read_buffer[5]);
	time_t timestamp = time(NULL);

	m_current_measurement.reset();
	m_current_measurement = std::make_shared<Aht10::Sensor::Measurement>(Measurement::create(temperature, humidity, timestamp));

	std::cout << "Read finished..." << std::endl;

	std::cout << "Measurement finished..." << std::endl;

	return true;
}

/// <summary>
/// Returns the current temperature measured by the sensor, converted to the specified unit.
/// </summary>
/// <param name="unit">
/// The temperature unit in which to return the result (e.g., Celsius, Fahrenheit, Kelvin, Rankine, Reaumur, or Raw).
/// </param>
/// <returns>
/// A Temperature object representing the current temperature in the requested unit.
/// </returns>
Aht10::Temperature Aht10::Sensor::getTemperature(Temperature::Unit unit) const
{
	if (!m_current_measurement) {
		throw std::logic_error("No measurement available. Call measure() first.");
	}

	const double celsius = m_current_measurement->temperature * 200.0 / (1 << 20) - 50.0;

	switch (unit) {
	case Temperature::Unit::Celsius:
		return Temperature::create(celsius, unit);
	case Temperature::Unit::Farenhiet:
		return Temperature::create(celsius * 1.8 + 32.0, unit);
	case Temperature::Unit::Kelvin:
		return Temperature::create(celsius + 273.15, unit);
	case Temperature::Unit::Rankine:
		return Temperature::create((celsius + 273.15) * 1.8, unit);
	case Temperature::Unit::Reaumur:
		return Temperature::create(celsius * 0.8, unit);
	default:
		return Temperature::create(m_current_measurement->temperature, Temperature::Unit::Raw);
	};
}

/// <summary>
/// Retrieves the timestamp of the current sensor reading.
/// </summary>
/// <returns>
/// The timestamp associated with the current sensor reading, as a time_t value.
/// </returns>
time_t Aht10::Sensor::getTimestamp() const
{
	if (!m_current_measurement) {
		throw std::logic_error("No measurement available. Call measure() first.");
	}

	return m_current_measurement->timestamp;
}

/// <summary>
/// Retrieves the current humidity measurement in the specified unit.
/// </summary>
/// <param name="unit">
/// The unit in which to return the humidity value (e.g., Percent, Ratio, or Raw).
/// </param>
/// <returns>
/// A Humidity object representing the current humidity in the requested unit.
/// </returns>
Aht10::Humidity Aht10::Sensor::getHumidity(Humidity::Unit unit) const
{
	if (!m_current_measurement) {
		throw std::logic_error("No measurement available. Call measure() first.");
	}

	switch (unit) {
	case Humidity::Unit::Percent:
		return Humidity::create(m_current_measurement->humidity * 100.0 / (1 << 20), unit);
	case Humidity::Unit::Ratio:
		return Humidity::create(m_current_measurement->humidity / (1 << 20), unit);
	default:
		return Humidity::create(m_current_measurement->humidity, Humidity::Unit::Raw);
	};
}

/// <summary>
/// Retrieves the current sensor reading as a Result object, using the specified temperature and humidity units.
/// </summary>
/// <param name="temperatureUnit">
/// The unit in which to return the temperature value.
/// </param>
/// <param name="humidityUnit">
/// The unit in which to return the humidity value.
/// </param>
/// <returns
/// >A Result object containing the temperature, humidity, and timestamp in the specified units.
/// </returns>
Aht10::Result Aht10::Sensor::getResult(Temperature::Unit temperatureUnit, Humidity::Unit humidityUnit) const
{
	return Aht10::Result::create(getTemperature(temperatureUnit), getHumidity(humidityUnit), getTimestamp());
}

/// <summary>
/// Retrieves a system status byte from the sensor.
/// </summary>
/// <returns>
/// The system status byte read from the sensor. Returns 0xFF if the read operation fails.
/// </returns>
Aht10::Status Aht10::Sensor::getStatus() const {
	uint8_t status;

	if (read(m_fd, &status, 1) != 1) {
		return Aht10::Status::Error;
	}

	return static_cast<Aht10::Status>(status);
}

/// <summary>
/// Resets the Aht10 sensor by sending a reset command and waiting for the sensor to become ready.
/// </summary>
void Aht10::Sensor::reset() {
	std::cout << "Reset starting..." << std::endl;

	m_write_buffer[0] = Command::Reset;

	if (write(m_fd, m_write_buffer, 1) != 1) {
		std::cerr << "Reset failed..." << std::endl;
		std::cout << "Reset finished..." << std::endl;
		return;
	}

	// Wait for the sensor to complete its reset per the AHT10 datasheet (>= 20 ms)
	const struct timespec reset_delay = { 0, 20000000L };
	nanosleep(&reset_delay, NULL);

	if (!Aht10::Sensor::waitForStatus(Status::Ready)) {
		std::cerr << "Reset failed..." << std::endl;
	}

	std::cout << "Reset finished..." << std::endl;
}

/// <summary>
/// Destroys the Sensor object and releases associated resources.
/// </summary>
Aht10::Sensor::~Sensor() {
	if (m_fd >= 0) {
		close(m_fd);
	}
}