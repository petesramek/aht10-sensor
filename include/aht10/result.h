#pragma once

#include "humidity.h"
#include "temperature.h"
#include <ctime>

namespace Aht10 {
	/// <summary>
	/// Represents a measurement result containing temperature, humidity, and a timestamp.
	/// </summary>
	struct Result
	{
	private:
		/// <summary>
		/// Constructs a Result object with the specified temperature, humidity, and timestamp.
		/// </summary>
		Result(Temperature temperature, Humidity humidity, time_t timestamp);

	public:
		/// <summary>
		/// A constant variable of type Temperature.
		/// </summary>
		const Temperature temperature;
		/// <summary>
		/// A constant variable representing humidity.
		/// </summary>
		const Humidity humidity;
		/// <summary>
		/// Represents a point in time as a timestamp.
		/// </summary>
		const time_t timestamp;

		/// <summary>
		/// Creates a Result object using the specified temperature, humidity, and timestamp.
		/// </summary>
		/// <param name="temperature">
		/// The temperature value to include in the result.
		/// </param>
		/// <param name="humidity">
		/// The humidity value to include in the result.
		/// </param>
		/// <param name="timestamp">
		/// The time at which the result is created.
		/// </param>
		/// <returns>
		/// A Result object containing the provided temperature, humidity, and timestamp.
		/// </returns>
		static Result create(Temperature temperature, Humidity humidity, time_t timestamp);
	};
}

