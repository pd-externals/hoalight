#include <gmock/gmock.h>
#include <Encoder.h>

using namespace testing;

using HoaEncoder2D = hoa::Encoder<hoa::Hoa2d, float>::Basic;
using HoaEncoder3D = hoa::Encoder<hoa::Hoa3d, float>::Basic;

TEST(IntegrationTest_Encoder2D, first_order)
{
    auto&& encoder2D = Encoder<HoaEncoder2D>(1);
    auto encoded = encoder2D.process();

    EXPECT_EQ(4, encoded.size());
}

TEST(IntegrationTest_Encoder2D, third_order)
{
    auto&& encoder2D = Encoder<HoaEncoder2D>(1);
    auto encoded = encoder2D.process();

    EXPECT_EQ(16, encoded.size());
}

TEST(IntegrationTest_Encoder3D, first_order)
{
    auto&& encoder3D = Encoder<HoaEncoder3D>(1);
    auto encoded = encoder3D.process();

    EXPECT_EQ(4, encoded.size());
}

TEST(IntegrationTest_Encoder3D, third_order)
{
    auto&& encoder3D = Encoder<HoaEncoder3D>(1);
    auto encoded = encoder3D.process();

    EXPECT_EQ(16, encoded.size());
}
