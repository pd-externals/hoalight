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
                BlauertTestData{0.f, 0.f, M_PI_2, M_PI_2}, // front
                BlauertTestData{0.f, 90.f, M_PI_2, 0.f} ,// top
                BlauertTestData{0.f, 90.1f, M_PI_2, 0.f} ,// top
                BlauertTestData{0.f, -90.f, M_PI_2, M_PI}, // bottom
                BlauertTestData{0.f, -90.1f, M_PI_2, M_PI}, // bottom
                BlauertTestData{-90.f, 0.f, M_PI, M_PI_2}, // left
                BlauertTestData{90.f, 0.f, 0.f, M_PI_2} ,// right
                BlauertTestData{180.f, 0.f, M_PI_2 + M_PI, M_PI_2}, // back
                BlauertTestData{180.1f, 0.f, M_PI_2 + M_PI, M_PI_2} // back
        ));
