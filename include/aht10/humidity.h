#pragma once

namespace Aht10 {
	/// <summary>
	/// Represents a humidity value with an associated unit.
	/// </summary>
	struct Humidity
	{

		/// <summary>
		/// Supported units for representing humidity values.
		/// </summary>
		enum Unit : int
		{
			/// <summary>
			/// Raw sensor value (no conversion applied).
			/// </summary>
			Raw = 0,

			/// <summary>
			/// Relative humidity as a percentage (%).
			/// </summary>
			Percent = 1,

			/// <summary>
			/// Humidity as a ratio (0.0 to 1.0).
			/// </summary>
			Ratio = 2,
		};

	private:
		/// <summary>
		/// Constructs a Humidity object with the specified value and unit.
		/// Private to enforce use of the static create method.
		/// </summary>
		/// <param name="value">The numeric humidity value.</param>
		/// <param name="unit">The unit of the humidity value.</param>
		Humidity(double value, Humidity::Unit unit);

	public:
		/// <summary>
		/// The numeric value of the humidity.
		/// </summary>
		double const value;

		/// <summary>
		/// The unit of the humidity value.
		/// </summary>
		Humidity::Unit const unit;

		/// <summary>
		/// Factory method to create a Humidity object.
		/// </summary>
		/// <param name="value">The numeric humidity value.</param>
		/// <param name="unit">The unit of the humidity value.</param>
		/// <returns>A Humidity object with the specified value and unit.</returns>
		static Humidity create(double value, Humidity::Unit unit);
	};
}