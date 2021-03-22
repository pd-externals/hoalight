cmake_minimum_required(VERSION 3.10)

project(HOALightWrapper)

add_subdirectory(ThirdParty/HoaLibrary-Light)
add_library(HOALightWrapper
        src/Adapter.cpp)
target_include_directories(HOALightWrapper PRIVATE include)

target_link_libraries(HOALightWrapper PRIVATE HoaLibrary)
