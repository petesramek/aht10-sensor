include(FetchContent)

FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG        v3.5.0
    GIT_SHALLOW    TRUE
)
FetchContent_MakeAvailable(Catch2)

add_executable(aht10_tests
    AHT10.Tests/address_tests.cpp
    AHT10.Tests/command_tests.cpp
    AHT10.Tests/humidity_tests.cpp
    AHT10.Tests/mode_tests.cpp
    AHT10.Tests/result_tests.cpp
    AHT10.Tests/status_tests.cpp
    AHT10.Tests/temperature_tests.cpp
)

target_link_libraries(aht10_tests PRIVATE aht10 Catch2::Catch2WithMain)

include(CTest)
include(Catch)
catch_discover_tests(aht10_tests)
