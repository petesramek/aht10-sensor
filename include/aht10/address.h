#pragma once

#include <cstdint>

namespace Aht10 {
	/// <summary>
	/// I2C address options for the AHT10 sensor.
	/// </summary>
	enum Address : uint8_t {
		/// <summary>
		/// Default I2C address (0x38) for most AHT10 sensors.
		/// </summary>
		DEFAULT = 0x38,

		/// <summary>
		/// Alternative I2C address (0x39) for configurable AHT10 sensors.
		/// </summary>
		ALTERNATIVE = 0x39,
	};
}