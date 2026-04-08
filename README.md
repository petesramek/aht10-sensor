# AHT10 Sensor

A C++ library for reading temperature and humidity from the [AHT10](https://asairsensors.com/en-us/product/aht10/) sensor over I²C on Linux (e.g. Raspberry Pi).

## Features

- Read temperature in Celsius, Fahrenheit, Kelvin, Rankine, or Réaumur
- Read humidity as a percentage or ratio
- Configurable I²C address (default `0x38`, alternative `0x39`)
- Soft reset and calibration support
- Cycle mode supported via `Aht10::Mode::Cycle`

## Requirements

- Linux with I²C support (`/dev/i2c-*`)
- C++17 compiler (e.g. GCC 9+)
- CMake 3.16+
- `libi2c-dev` for building the sensor driver

## Getting Started

### Install dependencies (Debian/Ubuntu)

```bash
sudo apt-get update
sudo apt-get install -y cmake g++ libi2c-dev
```

### Build

```bash
cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --parallel
```

### Run tests

```bash
ctest --test-dir build --output-on-failure
```

## Usage

```cpp
#include <aht10/sensor.h>

Aht10::Sensor sensor("/dev/i2c-1");

if (sensor.initialize(true)) {
    if (sensor.measure()) {
        auto result = sensor.getResult(
            Aht10::Temperature::Unit::Celsius,
            Aht10::Humidity::Unit::Percent);

        // result.temperature.value  -> temperature in °C
        // result.humidity.value     -> relative humidity in %
        // result.timestamp          -> Unix timestamp of measurement
    }
}
```

## Public API

All headers are individually includable under the `aht10/` prefix:

| Header | Contents |
|---|---|
| `<aht10/sensor.h>` | `Aht10::Sensor` — main sensor class |
| `<aht10/temperature.h>` | `Aht10::Temperature` value + `Temperature::Unit` enum |
| `<aht10/humidity.h>` | `Aht10::Humidity` value + `Humidity::Unit` enum |
| `<aht10/result.h>` | `Aht10::Result` (temperature + humidity + timestamp) |
| `<aht10/address.h>` | `Aht10::Address` enum (`DEFAULT = 0x38`, `ALTERNATIVE = 0x39`) |
| `<aht10/command.h>` | `Aht10::Command` enum (sensor command codes) |
| `<aht10/mode.h>` | `Aht10::Mode` enum (`Normal`, `Cycle`, `Calibration`) |
| `<aht10/status.h>` | `Aht10::Status` enum (`None`, `Calibrated`, `Ready`, `Busy`, `Error`) |

## Project Structure

```
include/
  aht10/          # Public headers (address, command, humidity, mode, result, sensor, status, temperature)
src/
  aht10/          # Library implementation (humidity, result, sensor, temperature)
tests/            # Unit tests (Catch2) — address, command, humidity, mode, result, status, temperature
.github/
  workflows/
    ci.yml        # GitHub Actions CI workflow
```

## Contributing

Pull requests are welcome. Please ensure all tests pass before submitting.
