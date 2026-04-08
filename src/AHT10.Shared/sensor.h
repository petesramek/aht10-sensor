#pragma once

#include <ctime>
#include <cerrno>
#include <fcntl.h>
#include <linux/i2c-dev.h>
#include <linux/ioctl.h>
#include <linux/types.h>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <memory>

#include "command.h"
#include "status.h"
#include "mode.h"
#include "temperature.h"
#include "humidity.h"
#include "result.h"

namespace Aht10 {
	/// <summary>
	/// Represents a sensor that measures temperature and humidity.
	/// </summary>
	class Sensor
	{
	private:
		/// <summary>
		/// Represents a measurement taken by the sensor, including temperature, humidity, and timestamp.
		/// </summary>
		struct Measurement
		{
		private:
			/// <summary>
			/// Constructs a Measurement object with the specified temperature, humidity, and timestamp.
			/// </summary>
			/// <param name="temperature">
			/// The temperature value to record.
			/// </param>
			/// <param name="humidity">
			/// The humidity value to record.
			/// </param>
			/// <param name="timestamp">
			/// The time at which the measurement was taken.
			/// </param>
			Measurement(double temperature, double humidity, time_t timestamp) : temperature(temperature), humidity(humidity), timestamp(timestamp) {}

		public:
			/// <summary>
			/// Represents a constant temperature value.
			/// </summary>
			const double temperature;
			/// <summary>
			/// Represents the humidity value as a constant double.
			/// </summary>
			const double humidity;
			/// <summary>
			/// Represents the timestamp of the measurement as a constant time_t.
			/// </summary>
			const time_t timestamp;

			/// <summary>
			/// Creates a new Measurement object with the specified temperature, humidity, and timestamp.
			/// </summary>
			/// <param name="temperature">
			/// The temperature value for the measurement.
			/// </param>
			/// <param name="humidity">
			/// The humidity value for the measurement.
			/// </param>
			/// <param name="timestamp">
			/// The time at which the measurement was taken.
			/// </param>
			/// <returns>
			/// A Measurement object initialized with the provided temperature, humidity, and timestamp.
			/// </returns>
			static Measurement create(double temperature, double humidity, time_t timestamp) {
				return Measurement(temperature, humidity, timestamp);
			}
		};

		/// <summary>
		/// Stores an 8-bit unsigned integer representing an I2C address.
		/// </summary>
		uint8_t m_address;

		/// <summary>
		/// A fixed-size array of three 8-bit unsigned integers.
		/// </summary>
		uint8_t m_write_buffer[3];

		/// <summary>
		/// A shared pointer to the current sensor measurement.
		/// </summary>
		std::shared_ptr<Sensor::Measurement> m_current_measurement;

		/// <summary>
		/// An array of 6 unsigned 8-bit integers.
		/// </summary>
		uint8_t m_read_buffer[6];

		/// <summary>
		/// A string representing the device identifier or name.
		/// </summary>
		std::string m_device;

		/// <summary>
		/// An integer representing a file descriptor.
		/// </summary>
		int m_fd;

		/// <summary>
		/// Waits for the sensor to reach a specific status.
		/// </summary>
		/// <param name="expected">
		/// The expected status to wait for.
		/// </param>
		/// <param name="maxIterations">
		/// The maximum number of iterations to wait for the status.
		/// </param>
		/// <param name="waitInterval">
		/// The interval in nanoseconds to wait between status checks.
		/// </param>
		/// <returns>
		/// True if the expected status is reached within the specified iterations, false otherwise.
		/// </returns>
		bool waitForStatus(Status expected, int maxIterations = 5, long waitInterval = 10000000L) const;

		/// <summary>
		/// Reads data from the sensor into the provided buffer.
		/// </summary>
		/// <returns>
		/// True if the read operation is successful, false otherwise.
		/// </returns>
		Aht10::Status getStatus() const;

		/// <summary>
		///Sets the current operating mode.
		/// </summary>
		/// <param name="mode">
		/// The mode to set.
		/// </param>
		/// <returns>
		/// True if the mode was set successfully; false otherwise.
		/// </returns>
		bool setMode(Mode mode);

	public:
		/// <summary>
		/// Constructs a Sensor object for the specified device.
		/// </summary>
		/// <param name="device">
		/// The name or identifier of the device to connect to.
		/// </param>
		/// <param name="useAlternateAddress">
		/// Whether to use an alternate address for the device. Defaults to false.
		/// </param>
		Sensor(std::string device, bool useAlternateAddress = false);

		Sensor(const Sensor&) = delete;
		Sensor& operator=(const Sensor&) = delete;
		Sensor(Sensor&&) = delete;
		Sensor& operator=(Sensor&&) = delete;

		/// <summary>
		/// Retrieves the humidity value in the specified unit.
		/// </summary>
		/// <param name="unit">
		/// The unit in which to return the humidity value (e.g., relative or absolute).
		/// </param>
		/// <returns>
		/// A Humidity object representing the humidity in the requested unit.
		/// </returns>
		Humidity getHumidity(Humidity::Unit unit) const;

		/// <summary>
		/// Retrieves a Result object based on the specified temperature and humidity units.
		/// </summary>
		/// <param name="temperatureUnit">
		/// The unit of temperature to use for the result.
		/// </param>
		/// <param name="humidityUnit">
		/// The unit of humidity to use for the result.
		/// </param>
		/// <returns>
		/// A Result object containing values in the specified temperature and humidity units.
		/// </returns>
		Result getResult(Temperature::Unit temperatureUnit, Humidity::Unit humidityUnit) const;

		/// <summary>
		/// Retrieves the temperature in the specified unit.
		/// </summary>
		/// <param name="unit">
		/// The unit in which to return the temperature (e.g., Celsius, Fahrenheit, Kelvin).
		/// </param>
		/// <returns>
		/// The temperature value represented in the specified unit.
		/// </returns>
		Temperature getTemperature(Temperature::Unit unit) const;

		/// <summary>
		/// Retrieves the timestamp of last measurement.
		/// </summary>
		/// <returns>
		/// The timestamp of last measurement as a value of type time_t.
		/// </returns>
		time_t getTimestamp() const;

		/// <summary>
		/// Initializes the system, optionally performing calibration.
		/// </summary>
		/// <param name="calibrate">
		/// If true, performs calibration during initialization; otherwise, skips calibration.
		/// </param>
		/// <returns>
		/// True if initialization succeeds; false otherwise.
		/// </returns>
		bool initialize(bool calibrate);

		/// <summary>
		/// Calibrates the sensor.
		/// </summary>
		/// <returns>
		/// True if calibration is successful; false otherwise.
		/// </returns>
		bool calibrate();

		/// <summary>
		/// Performs a measurement operation and returns the result as a boolean value.
		/// </summary>
		/// <returns>
		/// True if the measurement was successful or met the required condition; false otherwise.
		/// </returns>
		bool measure();

		/// <summary>
		/// Soft resets the sensor.
		/// </summary>
		void reset();

		/// <summary>
		/// Destroys the Sensor object and releases any associated resources.
		/// </summary>
		~Sensor();
	};
}