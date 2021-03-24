#include <gmock/gmock.h>
#include <Encoder2D.h>

using namespace testing;

TEST(IntegrationTest_Encoder2D, first_order)
{
    auto&& encoder2D = Encoder2D(1);
    auto encoded = encoder2D.process();

    EXPECT_EQ(4, encoded.size());
}

TEST(IntegrationTest_Encoder2D, third_order)
{
    auto&& encoder2D = Encoder2D(3);
    auto encoded = encoder2D.process();

    EXPECT_EQ(16, encoded.size());
}

