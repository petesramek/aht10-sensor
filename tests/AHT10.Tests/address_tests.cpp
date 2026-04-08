#include <catch2/catch_test_macros.hpp>
#include "address.h"

TEST_CASE("Default_Adress_Equals_0x38", "[Address]")
{
    Aht10::Address address = Aht10::Address::DEFAULT;

    REQUIRE(static_cast<int>(address) == 0x38);
    REQUIRE(static_cast<uint8_t>(address) == static_cast<uint8_t>(Aht10::Address::DEFAULT));
}

TEST_CASE("Alternative_Adress_Equals_0x39", "[Address]")
{
    Aht10::Address address = Aht10::Address::ALTERNATIVE;

    REQUIRE(static_cast<int>(address) == 0x39);
    REQUIRE(static_cast<uint8_t>(address) == static_cast<uint8_t>(Aht10::Address::ALTERNATIVE));
}
