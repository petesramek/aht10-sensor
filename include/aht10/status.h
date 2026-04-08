#pragma once

#include <cstdint>

namespace Aht10 {
    /// <summary>
    /// Status flags representing the current state of the AHT10 sensor.
    /// </summary>
    enum Status : uint8_t
    {
        /// <summary>
		/// Sensor status is unknown or not initialized.
        /// </summary>
        None = 0x00,

        /// <summary>
        /// Sensor is calibrated and ready for operation.
        /// </summary>
        Calibrated = 0x08,

        /// <summary>
        /// Sensor is ready to perform measurements.
        /// </summary>
        Ready = 0x30,

        /// <summary>
        /// Sensor is busy processing a command or measurement.
        /// </summary>
        Busy = 0x80,

		/// <summary>
		/// Sensor is in an error state or has encountered a failure.
		/// </summary>
		Error = 0xFF
    };
}