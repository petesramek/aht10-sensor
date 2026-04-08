#include <catch2/catch_test_macros.hpp>
#include <aht10/status.h>

TEST_CASE("None_Status_Equals_0x00", "[Status]")
{
    Aht10::Status status = Aht10::Status::None;

    REQUIRE(static_cast<int>(status) == 0x00);
    REQUIRE(static_cast<uint8_t>(status) == static_cast<uint8_t>(Aht10::Status::None));
}

TEST_CASE("Calibrated_Status_Equals_0x08", "[Status]")
{
    Aht10::Status status = Aht10::Status::Calibrated;

    REQUIRE(static_cast<int>(status) == 0x08);
    REQUIRE(static_cast<uint8_t>(status) == static_cast<uint8_t>(Aht10::Status::Calibrated));
}

TEST_CASE("Ready_Status_Equals_0x30", "[Status]")
{
    Aht10::Status status = Aht10::Status::Ready;

    REQUIRE(static_cast<int>(status) == 0x30);
    REQUIRE(static_cast<uint8_t>(status) == static_cast<uint8_t>(Aht10::Status::Ready));
}

TEST_CASE("Busy_Status_Equals_0x80", "[Status]")
{
    Aht10::Status status = Aht10::Status::Busy;

    REQUIRE(static_cast<int>(status) == 0x80);
    REQUIRE(static_cast<uint8_t>(status) == static_cast<uint8_t>(Aht10::Status::Busy));
}
