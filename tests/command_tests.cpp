#include <catch2/catch_test_macros.hpp>
#include <aht10/command.h>

TEST_CASE("Empty_Command_Equals_0x00", "[Command]")
{
    Aht10::Command command = Aht10::Command::Empty;

    REQUIRE(static_cast<int>(command) == 0x00);
    REQUIRE(static_cast<uint8_t>(command) == static_cast<uint8_t>(Aht10::Command::Empty));
}

TEST_CASE("Initialize_Command_Equals_0xE1", "[Command]")
{
    Aht10::Command command = Aht10::Command::Initialize;

    REQUIRE(static_cast<int>(command) == 0xE1);
    REQUIRE(static_cast<uint8_t>(command) == static_cast<uint8_t>(Aht10::Command::Initialize));
}

TEST_CASE("Calibrate_Command_Equals_0x08", "[Command]")
{
    Aht10::Command command = Aht10::Command::Calibrate;

    REQUIRE(static_cast<int>(command) == 0x08);
    REQUIRE(static_cast<uint8_t>(command) == static_cast<uint8_t>(Aht10::Command::Calibrate));
}

TEST_CASE("Measure_Command_Equals_0xAC", "[Command]")
{
    Aht10::Command command = Aht10::Command::Measure;

    REQUIRE(static_cast<int>(command) == 0xAC);
    REQUIRE(static_cast<uint8_t>(command) == static_cast<uint8_t>(Aht10::Command::Measure));
}

TEST_CASE("Read_Command_Equals_0x33", "[Command]")
{
    Aht10::Command command = Aht10::Command::Read;

    REQUIRE(static_cast<int>(command) == 0x33);
    REQUIRE(static_cast<uint8_t>(command) == static_cast<uint8_t>(Aht10::Command::Read));
}

TEST_CASE("Reset_Command_Equals_0xBA", "[Command]")
{
    Aht10::Command command = Aht10::Command::Reset;

    REQUIRE(static_cast<int>(command) == 0xBA);
    REQUIRE(static_cast<uint8_t>(command) == static_cast<uint8_t>(Aht10::Command::Reset));
}
