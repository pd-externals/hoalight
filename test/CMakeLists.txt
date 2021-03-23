cmake_minimum_required(VERSION 3.10)

add_executable(HOALightWrapper_Test
        UnitTest_Adapter.cpp
        UnitTest_Decoder.cpp
        UnitTest_Encoder.cpp
        UnitTest_Factory.cpp)

target_link_libraries(HOALightWrapper_Test
        PRIVATE
        HOALightWrapper
        gmock
        gtest_main)

