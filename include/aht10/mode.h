#pragma once

#include <cstdint>

namespace Aht10 {
    /// <summary>
    /// Operating modes for the AHT10 sensor.
    /// </summary>
    enum Mode : uint8_t
    {
        /// <summary>
        /// Normal mode: Standard measurement mode for regular sensor operation.
        /// </summary>
        Normal = 0x00,

        /// <summary>
        /// Cycle mode: Enables periodic measurement cycles for lower power consumption.
        /// </summary>
        Cycle = 0x20,

        /// <summary>
        /// Calibration mode: Used to calibrate the sensor for accurate readings.
        /// </summary>
        Calibration = 0x08
    };
}