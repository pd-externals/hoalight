cmake_minimum_required(VERSION 3.10)

add_executable(HOALightWrapper_Test
        UnitTest_HoaLight.cpp
#        UnitTest_Decoder.cpp
        UnitTest_Factory.cpp
        UnitTest_Blauert.cpp
        UnitTest_Pipeline.cpp
#        IntegrationTest_Encoder.cpp
        )

target_include_directories(HOALightWrapper_Test
        PRIVATE
        mocks)

target_link_libraries(HOALightWrapper_Test
        PRIVATE
        HOALightWrapper
        gmock
        gtest_main)

