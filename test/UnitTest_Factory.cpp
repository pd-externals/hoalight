#include <gmock/gmock.h>
#include <Encoder.h>

#include <Factory.h>

using namespace testing;

TEST(UnitTest_Factory, createEncoder)
{
    auto&& encoder = Factory().createEncoder2D(3);

    ASSERT_THAT(encoder, NotNull());
    auto* casted = dynamic_cast<Encoder<hoa::Encoder<hoa::Hoa2d, float>::Basic>*>(encoder.get());
    EXPECT_THAT(casted, NotNull());
}

TEST(UnitTest_Factory, createEncoder3D)
{
    auto&& encoder3D = Factory().createEncoder3D(3);

    ASSERT_THAT(encoder3D, NotNull());
    auto* casted = dynamic_cast<Encoder<hoa::Encoder<hoa::Hoa3d, float>::Basic>*>(encoder3D.get());
    EXPECT_THAT(casted, NotNull());
}
//
//TEST(UnitTest_Factory, createEncoder3D)
//{
//    auto&& encoder3D = Factory().createEncoder3D(3);
//
//    ASSERT_THAT(encoder3D, NotNull());
//    EXPECT_THAT(encoder3D.get(), WhenDynamicCastTo<Encoder3D*>(NotNull()));
//}
