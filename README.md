# AHT10 Sensor

A C++ library for reading temperature and humidity from the [AHT10](https://asairsensors.com/en-us/product/aht10/) sensor over I²C on Linux (e.g. Raspberry Pi).

## Features

- Read temperature in Celsius, Fahrenheit, Kelvin, Rankine, or Réaumur
- Read humidity as a percentage or ratio
- Configurable I²C address (default `0x38`, alternative `0x39`)
- Soft reset and calibration support
- Periodic measurement loop via `Cycle`

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
#include "sensor.h"

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

## Project Structure

```
src/
  AHT10.Shared/   # Library source (temperature, humidity, result, sensor, cycle)
tests/
  AHT10.Tests/    # Unit tests (Catch2)
.github/
  workflows/
    ci.yml        # GitHub Actions CI workflow
```

## Contributing

Pull requests are welcome. Please ensure all tests pass before submitting.
