#include <gmock/gmock.h>
#include "Encoder.h"
#include "Encoder2D.h"
#include "Encoder3D.h"
#include "Factory.h"

using namespace testing;

TEST(Factory, CreateEncoder)
{
    auto&& encoder = Factory().CreateEncoder(Dimension::THREE, 3);

    ASSERT_THAT(encoder, NotNull());
    EXPECT_THAT(encoder.get(), WhenDynamicCastTo<Encoder*>(NotNull()));
}

TEST(Factory, CreateEncoder2D)
{
    auto&& encoder2D = Factory().CreateEncoder2D(3);

    ASSERT_THAT(encoder2D, NotNull());
    EXPECT_THAT(encoder2D.get(), WhenDynamicCastTo<Encoder2D*>(NotNull()));
}

TEST(Factory, CreateEncoder3D)
{
    auto&& encoder3D = Factory().CreateEncoder3D(3);

    ASSERT_THAT(encoder3D, NotNull());
    EXPECT_THAT(encoder3D.get(), WhenDynamicCastTo<Encoder3D*>(NotNull()));
}
