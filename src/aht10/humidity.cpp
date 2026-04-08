#include <aht10/humidity.h>

/// <summary>
/// Constructs a Humidity object with the specified value and unit.
/// </summary>
/// <param name="value">
/// The numeric humidity value.
/// </param>
/// <param name="unit">
/// The unit of the humidity value.
/// </param>
Aht10::Humidity::Humidity(double value, Humidity::Unit unit) : value(value), unit(unit) {};

/// <summary>
/// Factory method to create a Humidity object.
/// </summary>
/// <param name="value">
/// The numeric humidity value.
/// </param>
/// <param name="unit">
/// The unit of the humidity value.
/// </param>
/// <returns>
/// A Humidity object with the specified value and unit.
/// </returns>
Aht10::Humidity Aht10::Humidity::create(double value, Humidity::Unit unit)
{
	return Humidity(value, unit);
}