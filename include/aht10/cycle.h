#pragma once

#include <cstdint>
#include "sensor.h"
#include "result.h"

/// <summary>
/// Runs a periodic measurement loop using an AHT10 sensor.
/// </summary>
class Cycle
{
public:
	/// <summary>
	/// Constructs a Cycle object with the specified sensor, units, and interval.
	/// </summary>
	Cycle(Aht10::Sensor& sensor, Aht10::Temperature::Unit temperatureUnit, Aht10::Humidity::Unit humidityUnit, uint interval);

	Cycle(const Cycle&) = delete;
	Cycle& operator=(const Cycle&) = delete;
	Cycle(Cycle&&) = delete;
	Cycle& operator=(Cycle&&) = delete;

	/// <summary>
	/// Creates a Cycle object with the specified sensor, units, and interval.
	/// </summary>
	static Cycle create(Aht10::Sensor& sensor, Aht10::Temperature::Unit temperatureUnit, Aht10::Humidity::Unit humidityUnit, uint interval);

	/// <summary>
	/// Starts the measurement loop, calling func_ptr with each result.
	/// </summary>
	void start(void(*func_ptr)(Aht10::Result));

	/// <summary>
	/// Stops the measurement loop.
	/// </summary>
	void stop();

	~Cycle();

private:
	Aht10::Sensor& m_sensor;
	Aht10::Temperature::Unit m_temperatureUnit;
	Aht10::Humidity::Unit m_humidityUnit;
	uint m_interval;
	bool m_running = false;
	bool m_terminate = false;
};
