#include <catch2/catch_test_macros.hpp>
#include <aht10/humidity.h>

TEST_CASE("Humidity_Create_Returns_Instance_With_Values_Zero_And_Raw", "[Humidity]")
{
    double value = 0.0;
    Aht10::Humidity::Unit unit = Aht10::Humidity::Unit::Raw;

    Aht10::Humidity humidity = Aht10::Humidity::create(value, unit);

    REQUIRE(humidity.value == value);
    REQUIRE(static_cast<uint8_t>(humidity.unit) == static_cast<uint8_t>(unit));
}

TEST_CASE("Humidity_Create_Returns_Instance_With_Values_Zero_And_Percent", "[Humidity]")
{
    double value = 0.0;
    Aht10::Humidity::Unit unit = Aht10::Humidity::Unit::Percent;

    Aht10::Humidity humidity = Aht10::Humidity::create(value, unit);

    REQUIRE(humidity.value == value);
    REQUIRE(static_cast<uint8_t>(humidity.unit) == static_cast<uint8_t>(unit));
}

TEST_CASE("Humidity_Create_Returns_Instance_With_Values_Zero_And_Ratio", "[Humidity]")
{
    double value = 10.0;
    Aht10::Humidity::Unit unit = Aht10::Humidity::Unit::Ratio;

    Aht10::Humidity humidity = Aht10::Humidity::create(value, unit);

    REQUIRE(humidity.value == value);
    REQUIRE(static_cast<uint8_t>(humidity.unit) == static_cast<uint8_t>(unit));
}

TEST_CASE("Humidity_Create_Returns_Instance_With_Values_Positive_Ten_And_Raw", "[Humidity]")
{
    double value = 10.0;
    Aht10::Humidity::Unit unit = Aht10::Humidity::Unit::Raw;

    Aht10::Humidity humidity = Aht10::Humidity::create(value, unit);

    REQUIRE(humidity.value == value);
    REQUIRE(static_cast<uint8_t>(humidity.unit) == static_cast<uint8_t>(unit));
}

TEST_CASE("Humidity_Create_Returns_Instance_With_Values_Positive_Ten_And_Percent", "[Humidity]")
{
    double value = 10.0;
    Aht10::Humidity::Unit unit = Aht10::Humidity::Unit::Percent;

    Aht10::Humidity humidity = Aht10::Humidity::create(value, unit);

    REQUIRE(humidity.value == value);
    REQUIRE(static_cast<uint8_t>(humidity.unit) == static_cast<uint8_t>(unit));
}

TEST_CASE("Humidity_Create_Returns_Instance_With_Values_Positive_Ten_And_Ratio", "[Humidity]")
{
    double value = 10.0;
    Aht10::Humidity::Unit unit = Aht10::Humidity::Unit::Ratio;

    Aht10::Humidity humidity = Aht10::Humidity::create(value, unit);

    REQUIRE(humidity.value == value);
    REQUIRE(static_cast<uint8_t>(humidity.unit) == static_cast<uint8_t>(unit));
}

TEST_CASE("Humidity_Create_Returns_Instance_With_Values_Negative_Ten_And_Raw", "[Humidity]")
{
    double value = -10.0;
    Aht10::Humidity::Unit unit = Aht10::Humidity::Unit::Raw;

    Aht10::Humidity humidity = Aht10::Humidity::create(value, unit);

    REQUIRE(humidity.value == value);
    REQUIRE(static_cast<uint8_t>(humidity.unit) == static_cast<uint8_t>(unit));
}

TEST_CASE("Humidity_Create_Returns_Instance_With_Values_Negative_Ten_And_Percent", "[Humidity]")
{
    double value = -10.0;
    Aht10::Humidity::Unit unit = Aht10::Humidity::Unit::Percent;

    Aht10::Humidity humidity = Aht10::Humidity::create(value, unit);

    REQUIRE(humidity.value == value);
    REQUIRE(static_cast<uint8_t>(humidity.unit) == static_cast<uint8_t>(unit));
}

TEST_CASE("Humidity_Create_Returns_Instance_With_Values_Negative_Ten_And_Ratio", "[Humidity]")
{
    double value = -10.0;
    Aht10::Humidity::Unit unit = Aht10::Humidity::Unit::Ratio;

    Aht10::Humidity humidity = Aht10::Humidity::create(value, unit);

    REQUIRE(humidity.value == value);
    REQUIRE(static_cast<uint8_t>(humidity.unit) == static_cast<uint8_t>(unit));
}
