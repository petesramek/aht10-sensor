#pragma once

namespace Aht10 {
	/// <summary>
	/// Represents a temperature value with an associated unit.
	/// </summary>
	struct Temperature
	{
		/// <summary>
		/// Represents supported temperature units for sensor readings.
		/// </summary>
		enum Unit : int
		{
			/// <summary>Raw sensor value (no conversion applied).</summary>
			Raw = 0,

			/// <summary>Degrees Celsius (°C).</summary>
			Celsius = 1,

			/// <summary>Degrees Fahrenheit (°F).</summary>
			Farenhiet = 2,

			/// <summary>Kelvin (K).</summary>
			Kelvin = 3,

			/// <summary>Rankine (°R).</summary>
			Rankine = 4,

			/// <summary>Réaumur (°Ré).</summary>
			Reaumur = 5,
		};
	private:
		/// <summary>
		/// Constructs a Temperature object with the specified value and unit.
		/// Private to enforce use of the static create method.
		/// </summary>
		/// <param name="value">The numeric temperature value.</param>
		/// <param name="unit">The unit of the temperature.</param>
		Temperature(double value, Temperature::Unit unit);

	public:
		/// <summary>
		/// The numeric value of the temperature.
		/// </summary>
		double const value;

		/// <summary>
		/// The unit of the temperature value.
		/// </summary>
		Temperature::Unit const unit;

		/// <summary>
		/// Factory method to create a Temperature object.
		/// </summary>
		/// <param name="value">The numeric temperature value.</param>
		/// <param name="unit">The unit of the temperature.</param>
		/// <returns>A Temperature object with the specified value and unit.</returns>
		static Temperature create(double value, Temperature::Unit unit);
	};
}