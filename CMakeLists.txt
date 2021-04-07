cmake_minimum_required(VERSION 3.10)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/lib)
set(CMAKE_OSX_DEPLOYMENT_TARGET "10.9")
project(HOALightWrapper)

add_subdirectory(ThirdParty)
add_subdirectory(test)

add_library(HOALightWrapper
        src/HoaLight.cpp
        src/Encoder.cpp
        src/Encoder2D.cpp
        src/Encoder3D.cpp
        src/Wider2D.cpp
        src/Wider3D.cpp
        src/OptimInPhase2D.cpp
        src/OptimInPhase3D.cpp
        src/OptimMaxRe2D.cpp
        src/OptimMaxRe3D.cpp
        src/Decoder.cpp
        src/Decoder2D.cpp
        src/Decoder3D.cpp
        src/Factory.cpp
        src/Blauert.cpp
        src/HoaLightWrapper.cpp)

target_compile_features(HOALightWrapper PUBLIC cxx_std_17)
target_include_directories(HOALightWrapper
        PUBLIC
        include
        ThirdParty/HoaLibrary-Light/Sources)

target_link_libraries(HOALightWrapper PUBLIC HoaLibrary)

