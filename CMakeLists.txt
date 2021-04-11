cmake_minimum_required(VERSION 3.10)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/lib)
set(CMAKE_OSX_DEPLOYMENT_TARGET "10.9")
project(HOALightWrapper)

add_subdirectory(ThirdParty)
add_subdirectory(test)

add_library(HOALightWrapper
        src/HoaLight.cpp
        src/Pipeline.cpp
        src/Factory.cpp
        src/Blauert.cpp
        src/HoaLightWrapper.cpp)

target_compile_features(HOALightWrapper PUBLIC cxx_std_17)
target_include_directories(HOALightWrapper
        PUBLIC
        include
        ThirdParty/HoaLibrary-Light/Sources)

