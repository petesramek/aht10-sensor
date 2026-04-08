#include <catch2/catch_test_macros.hpp>
#include "mode.h"

TEST_CASE("Normal_Mode_Equals_0x00", "[Mode]")
{
    Aht10::Mode mode = Aht10::Mode::Normal;

    REQUIRE(static_cast<int>(mode) == 0x00);
    REQUIRE(static_cast<uint8_t>(mode) == static_cast<uint8_t>(Aht10::Mode::Normal));
}

TEST_CASE("Cycle_Mode_Equals_0x20", "[Mode]")
{
    Aht10::Mode mode = Aht10::Mode::Cycle;

    REQUIRE(static_cast<int>(mode) == 0x20);
    REQUIRE(static_cast<uint8_t>(mode) == static_cast<uint8_t>(Aht10::Mode::Cycle));
}

TEST_CASE("Calibration_Mode_Equals_0x08", "[Mode]")
{
    Aht10::Mode mode = Aht10::Mode::Calibration;

    REQUIRE(static_cast<int>(mode) == 0x08);
    REQUIRE(static_cast<uint8_t>(mode) == static_cast<uint8_t>(Aht10::Mode::Calibration));
}
