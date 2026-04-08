#include "cycle.h"
#include "sensor.h"
#include <unistd.h>

Cycle::Cycle(Aht10::Sensor& sensor, Aht10::Temperature::Unit temperatureUnit, Aht10::Humidity::Unit humidityUnit, uint interval)
	: m_sensor(sensor), m_temperatureUnit(temperatureUnit), m_humidityUnit(humidityUnit), m_interval(interval) { }

Cycle Cycle::create(Aht10::Sensor& sensor, Aht10::Temperature::Unit temperatureUnit, Aht10::Humidity::Unit humidityUnit, uint interval)
{
	return Cycle(sensor, temperatureUnit, humidityUnit, interval);
}

void Cycle::start(void(*func_ptr)(Aht10::Result))
{
	if (m_running)
	{
		return;
	}

	m_running = true;

	while (!m_terminate)
	{
		if (func_ptr != nullptr)
		{
			if (m_sensor.measure()) {
				
				auto result = m_sensor.getResult(m_temperatureUnit, m_humidityUnit);
				func_ptr(result);
			}
			
		}

		sleep(m_interval);
	}

	m_running = false;
}

void Cycle::stop()
{
	if (!m_running) {
		m_terminate = false;
		return;
	}

	m_terminate = true;

	while (m_running)
	{
		usleep(10);
	}

	m_terminate = false;
}

Cycle::~Cycle()
{
	stop();
}
