#include <aht10/temperature.h>

/// <summary>
/// Constructs a Temperature object with the specified value and unit.
/// </summary>
/// <param name="value">
/// The numeric temperature value.
/// </param>
/// <param name="unit">
/// The unit of the temperature value.
/// </param>
Aht10::Temperature::Temperature(double value, Temperature::Unit unit) : value(value), unit(unit) {};

/// <summary>
/// Factory method to create a Temperature object.
/// </summary>
/// <param name="value">
/// The numeric temperature value.
/// </param>
/// <param name="unit">
/// The unit of the temperature value.
/// </param>
/// <returns>
/// A Temperature object with the specified value and unit.
/// </returns>
Aht10::Temperature Aht10::Temperature::create(double value, Temperature::Unit unit)
{
	return Temperature(value, unit);
}