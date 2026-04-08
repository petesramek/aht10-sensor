#include <catch2/catch_test_macros.hpp>
#include <aht10/temperature.h>

TEST_CASE("Temperature_Create_Returns_Instance_With_Values_Zero_And_Raw", "[Temperature]")
{
    double value = 0.0;
    Aht10::Temperature::Unit unit = Aht10::Temperature::Unit::Raw;

    Aht10::Temperature temperature = Aht10::Temperature::create(value, unit);

    REQUIRE(temperature.value == value);
    REQUIRE(static_cast<uint8_t>(temperature.unit) == static_cast<uint8_t>(unit));
}

TEST_CASE("Temperature_Create_Returns_Instance_With_Values_Zero_And_Celsius", "[Temperature]")
{
    double value = 0.0;
    Aht10::Temperature::Unit unit = Aht10::Temperature::Unit::Celsius;

    Aht10::Temperature temperature = Aht10::Temperature::create(value, unit);

    REQUIRE(temperature.value == value);
    REQUIRE(static_cast<uint8_t>(temperature.unit) == static_cast<uint8_t>(unit));
}

TEST_CASE("Temperature_Create_Returns_Instance_With_Values_Zero_And_Farenhiet", "[Temperature]")
{
    double value = 0.0;
    Aht10::Temperature::Unit unit = Aht10::Temperature::Unit::Farenhiet;

    Aht10::Temperature temperature = Aht10::Temperature::create(value, unit);

    REQUIRE(temperature.value == value);
    REQUIRE(static_cast<uint8_t>(temperature.unit) == static_cast<uint8_t>(unit));
}

TEST_CASE("Temperature_Create_Returns_Instance_With_Values_Zero_And_Kelvin", "[Temperature]")
{
    double value = 0.0;
    Aht10::Temperature::Unit unit = Aht10::Temperature::Unit::Kelvin;

    Aht10::Temperature temperature = Aht10::Temperature::create(value, unit);

    REQUIRE(temperature.value == value);
    REQUIRE(static_cast<uint8_t>(temperature.unit) == static_cast<uint8_t>(unit));
}

TEST_CASE("Temperature_Create_Returns_Instance_With_Values_Zero_And_Rankine", "[Temperature]")
{
    double value = 0.0;
    Aht10::Temperature::Unit unit = Aht10::Temperature::Unit::Rankine;

    Aht10::Temperature temperature = Aht10::Temperature::create(value, unit);

    REQUIRE(temperature.value == value);
    REQUIRE(static_cast<uint8_t>(temperature.unit) == static_cast<uint8_t>(unit));
}

TEST_CASE("Temperature_Create_Returns_Instance_With_Values_Zero_And_Reaumur", "[Temperature]")
{
    double value = 0.0;
    Aht10::Temperature::Unit unit = Aht10::Temperature::Unit::Reaumur;

    Aht10::Temperature temperature = Aht10::Temperature::create(value, unit);

    REQUIRE(temperature.value == value);
    REQUIRE(static_cast<uint8_t>(temperature.unit) == static_cast<uint8_t>(unit));
}

TEST_CASE("Temperature_Create_Returns_Instance_With_Values_Positive_Ten_And_Raw", "[Temperature]")
{
    double value = 10.0;
    Aht10::Temperature::Unit unit = Aht10::Temperature::Unit::Raw;

    Aht10::Temperature temperature = Aht10::Temperature::create(value, unit);

    REQUIRE(temperature.value == value);
    REQUIRE(static_cast<uint8_t>(temperature.unit) == static_cast<uint8_t>(unit));
}

TEST_CASE("Temperature_Create_Returns_Instance_With_Values_Positive_Ten_And_Celsius", "[Temperature]")
{
    double value = 10.0;
    Aht10::Temperature::Unit unit = Aht10::Temperature::Unit::Celsius;

    Aht10::Temperature temperature = Aht10::Temperature::create(value, unit);

    REQUIRE(temperature.value == value);
    REQUIRE(static_cast<uint8_t>(temperature.unit) == static_cast<uint8_t>(unit));
}

TEST_CASE("Temperature_Create_Returns_Instance_With_Values_Positive_Ten_And_Farenhiet", "[Temperature]")
{
    double value = 10.0;
    Aht10::Temperature::Unit unit = Aht10::Temperature::Unit::Farenhiet;

    Aht10::Temperature temperature = Aht10::Temperature::create(value, unit);

    REQUIRE(temperature.value == value);
    REQUIRE(static_cast<uint8_t>(temperature.unit) == static_cast<uint8_t>(unit));
}

TEST_CASE("Temperature_Create_Returns_Instance_With_Values_Positive_Ten_And_Kelvin", "[Temperature]")
{
    double value = 10.0;
    Aht10::Temperature::Unit unit = Aht10::Temperature::Unit::Kelvin;

    Aht10::Temperature temperature = Aht10::Temperature::create(value, unit);

    REQUIRE(temperature.value == value);
    REQUIRE(static_cast<uint8_t>(temperature.unit) == static_cast<uint8_t>(unit));
}

TEST_CASE("Temperature_Create_Returns_Instance_With_Values_Positive_Ten_And_Rankine", "[Temperature]")
{
    double value = 10.0;
    Aht10::Temperature::Unit unit = Aht10::Temperature::Unit::Rankine;

    Aht10::Temperature temperature = Aht10::Temperature::create(value, unit);

    REQUIRE(temperature.value == value);
    REQUIRE(static_cast<uint8_t>(temperature.unit) == static_cast<uint8_t>(unit));
}

TEST_CASE("Temperature_Create_Returns_Instance_With_Values_Positive_Ten_And_Reaumur", "[Temperature]")
{
    double value = 10.0;
    Aht10::Temperature::Unit unit = Aht10::Temperature::Unit::Reaumur;

    Aht10::Temperature temperature = Aht10::Temperature::create(value, unit);

    REQUIRE(temperature.value == value);
    REQUIRE(static_cast<uint8_t>(temperature.unit) == static_cast<uint8_t>(unit));
}

TEST_CASE("Temperature_Create_Returns_Instance_With_Values_Negative_Ten_And_Raw", "[Temperature]")
{
    double value = -10.0;
    Aht10::Temperature::Unit unit = Aht10::Temperature::Unit::Raw;

    Aht10::Temperature temperature = Aht10::Temperature::create(value, unit);

    REQUIRE(temperature.value == value);
    REQUIRE(static_cast<uint8_t>(temperature.unit) == static_cast<uint8_t>(unit));
}

TEST_CASE("Temperature_Create_Returns_Instance_With_Values_Negative_Ten_And_Celsius", "[Temperature]")
{
    double value = -10.0;
    Aht10::Temperature::Unit unit = Aht10::Temperature::Unit::Celsius;

    Aht10::Temperature temperature = Aht10::Temperature::create(value, unit);

    REQUIRE(temperature.value == value);
    REQUIRE(static_cast<uint8_t>(temperature.unit) == static_cast<uint8_t>(unit));
}

TEST_CASE("Temperature_Create_Returns_Instance_With_Values_Negative_Ten_And_Farenhiet", "[Temperature]")
{
    double value = -10.0;
    Aht10::Temperature::Unit unit = Aht10::Temperature::Unit::Farenhiet;

    Aht10::Temperature temperature = Aht10::Temperature::create(value, unit);

    REQUIRE(temperature.value == value);
    REQUIRE(static_cast<uint8_t>(temperature.unit) == static_cast<uint8_t>(unit));
}

TEST_CASE("Temperature_Create_Returns_Instance_With_Values_Negative_Ten_And_Kelvin", "[Temperature]")
{
    double value = -10.0;
    Aht10::Temperature::Unit unit = Aht10::Temperature::Unit::Kelvin;

    Aht10::Temperature temperature = Aht10::Temperature::create(value, unit);

    REQUIRE(temperature.value == value);
    REQUIRE(static_cast<uint8_t>(temperature.unit) == static_cast<uint8_t>(unit));
}

TEST_CASE("Temperature_Create_Returns_Instance_With_Values_Negative_Ten_And_Rankine", "[Temperature]")
{
    double value = -10.0;
    Aht10::Temperature::Unit unit = Aht10::Temperature::Unit::Rankine;

    Aht10::Temperature temperature = Aht10::Temperature::create(value, unit);

    REQUIRE(temperature.value == value);
    REQUIRE(static_cast<uint8_t>(temperature.unit) == static_cast<uint8_t>(unit));
}

TEST_CASE("Temperature_Create_Returns_Instance_With_Values_Negative_Ten_And_Reaumur", "[Temperature]")
{
    double value = -10.0;
    Aht10::Temperature::Unit unit = Aht10::Temperature::Unit::Reaumur;

    Aht10::Temperature temperature = Aht10::Temperature::create(value, unit);

    REQUIRE(temperature.value == value);
    REQUIRE(static_cast<uint8_t>(temperature.unit) == static_cast<uint8_t>(unit));
}
