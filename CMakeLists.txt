cmake_minimum_required(VERSION 3.10)

project(HOALightWrapper)

add_subdirectory(ThirdParty)
add_subdirectory(test)

add_library(HOALightWrapper
        src/Adapter.cpp
        src/Encoder.cpp
        src/Encoder2D.cpp
        src/Encoder3D.cpp
        src/Decoder.cpp
        src/Factory.cpp
        src/Blauert.cpp)

target_compile_features(HOALightWrapper PUBLIC cxx_std_17)
target_include_directories(HOALightWrapper PUBLIC include)
target_link_libraries(HOALightWrapper PUBLIC HoaLibrary)

