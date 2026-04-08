#pragma once

#include <cstdint>

namespace Aht10 {
    /// <summary>
    /// Command codes for controlling the AHT10 sensor.
    /// </summary>
    enum Command : uint8_t
    {
        /// <summary>
        /// No operation or empty command.
        /// </summary>
        Empty = 0x00,

        /// <summary>
        /// Initialize the sensor.
        /// </summary>
        Initialize = 0xE1,

        /// <summary>
        /// Calibrate the sensor for accurate measurements.
        /// </summary>
        Calibrate = 0x08,

        /// <summary>
        /// Trigger a measurement operation.
        /// </summary>
        Measure = 0xAC,

        /// <summary>
        /// Read data from the sensor.
        /// </summary>
        Read = 0x33,

        /// <summary>
        /// Reset the sensor to its default state.
        /// </summary>
        Reset = 0xBA,
    };
}