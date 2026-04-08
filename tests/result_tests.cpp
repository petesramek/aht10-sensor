#include <catch2/catch_test_macros.hpp>
#include <aht10/result.h>

TEST_CASE("Result_Create_Returns_Instance_With_Values_Zero_And_Raw", "[Result]")
{
    time_t timestamp = 0;
    Aht10::Humidity humidity = Aht10::Humidity::create(0.0, Aht10::Humidity::Unit::Raw);
    Aht10::Temperature temperature = Aht10::Temperature::create(0.0, Aht10::Temperature::Unit::Raw);

    Aht10::Result result = Aht10::Result::create(temperature, humidity, timestamp);

    REQUIRE(result.humidity.value == humidity.value);
    REQUIRE(static_cast<uint8_t>(result.humidity.unit) == static_cast<uint8_t>(humidity.unit));
    REQUIRE(result.temperature.value == temperature.value);
    REQUIRE(static_cast<uint8_t>(result.temperature.unit) == static_cast<uint8_t>(temperature.unit));
    REQUIRE(result.timestamp == timestamp);
}
