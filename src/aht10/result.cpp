#include <aht10/result.h>

/// <summary>
/// Represents the result of a measurement from the AHT10 sensor.
/// </summary>
/// <param name="temperature">
/// The temperature measurement.
/// </param>
/// <param name="humidity">
/// The humidity measurement.
/// </param>
/// <param name="timestamp">
/// The timestamp of the measurement, in seconds since the epoch (January 1, 1970).
/// </param>
Aht10::Result::Result(Temperature temperature, Humidity humidity, time_t timestamp)
	: temperature(temperature), humidity(humidity), timestamp(timestamp) { }

/// <summary>
/// Creates a new Aht10::Result object with the specified temperature, humidity, and timestamp.
/// </summary>
/// <param name="temperature">
/// The temperature value to store in the result.
/// </param>
/// <param name="humidity">
/// The humidity value to store in the result.
/// </param>
/// <param name="timestamp">
/// The time at which the measurement was taken.
/// </param>
/// <returns>A new Aht10::Result object initialized with the given temperature, humidity, and timestamp.</returns>
Aht10::Result Aht10::Result::create(Temperature temperature, Humidity humidity, time_t timestamp)
{
	return Result(temperature, humidity, timestamp);
}
