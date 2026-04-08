add_library(aht10 STATIC
    aht10/temperature.cpp
    aht10/humidity.cpp
    aht10/result.cpp
    aht10/sensor.cpp
)

target_include_directories(aht10 PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_compile_features(aht10 PUBLIC cxx_std_17)
