add_library(aht10 STATIC
    AHT10.Shared/temperature.cpp
    AHT10.Shared/humidity.cpp
    AHT10.Shared/result.cpp
)

target_include_directories(aht10 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/AHT10.Shared)
target_compile_features(aht10 PUBLIC cxx_std_17)
