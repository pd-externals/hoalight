#include <gmock/gmock.h>
#include <Encoder.h>
#include <Encoder2D.h>
#include <Encoder3D.h>
#include <Factory.h>

using namespace testing;

TEST(UnitTest_Factory, createEncoder)
{
    auto&& encoder = Factory().createEncoder(Dimension::THREE, 3);

    ASSERT_THAT(encoder, NotNull());
    EXPECT_THAT(encoder.get(), WhenDynamicCastTo<Encoder*>(NotNull()));
}

TEST(UnitTest_Factory, createEncoder2D)
{
    auto&& encoder2D = Factory().createEncoder2D(3);

    ASSERT_THAT(encoder2D, NotNull());
    EXPECT_THAT(encoder2D.get(), WhenDynamicCastTo<Encoder2D*>(NotNull()));
}

TEST(UnitTest_Factory, createEncoder3D)
{
    auto&& encoder3D = Factory().createEncoder3D(3);

    ASSERT_THAT(encoder3D, NotNull());
    EXPECT_THAT(encoder3D.get(), WhenDynamicCastTo<Encoder3D*>(NotNull()));
}
