#include <gmock/gmock.h>
#include <Blauert.h>

using namespace testing;

struct BlauertTestData
{
    float azimuth;
    float elevation;
    float expectedPhi;
    float expectedTheta;
};

class UnitTest_Blauert :public ::testing::TestWithParam<BlauertTestData> {

};

TEST_P(UnitTest_Blauert, conversion)
{
    auto params = GetParam();
    auto phi = Blauert::toPhi(params.azimuth);
    auto theta = Blauert::toTheta(params.elevation);

    EXPECT_EQ(params.expectedPhi, phi);
    EXPECT_EQ(params.expectedTheta, theta);
}

INSTANTIATE_TEST_SUITE_P(
        ParameterizedTest_Blauert,
        UnitTest_Blauert,
        Values(
                BlauertTestData{0.f, 0.f, 0.f, 0.f}, // front
                BlauertTestData{0.f, 90.f, 0.f, M_PI_2} ,// top
                BlauertTestData{0.f, -90.f, 0.f, -M_PI_2}, // bottom
                BlauertTestData{-90.f, 0.f, M_PI_2, 0.f}, // left
                BlauertTestData{90.f, 0.f, -M_PI_2, 0.f} ,// right
                BlauertTestData{180.f, 0.f, -M_PI, 0.f}, // back
                BlauertTestData{360.f, 0.f, -M_PI * 2.f, 0.f}, // front
                BlauertTestData{-360.f, 0.f, M_PI * 2.f, 0.f} // front

        )
);
