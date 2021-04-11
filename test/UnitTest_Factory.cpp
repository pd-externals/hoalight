#include <gmock/gmock.h>
#include <Encoder.h>
#include <Wider.h>
#include <Optim.h>
#include <Decoder.h>
#include <Pipeline.h>
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

TEST(UnitTest_Factory, createWider2D)
{
    auto&& wider2D = Factory().createWider2D(3);

    ASSERT_THAT(wider2D, NotNull());
    auto* casted = dynamic_cast<Wider<hoa::Wider<hoa::Hoa2d, float>>*>(wider2D.get());
    EXPECT_THAT(casted, NotNull());
}

TEST(UnitTest_Factory, createWider3D)
{
    auto&& wider3D = Factory().createWider3D(3);

    ASSERT_THAT(wider3D, NotNull());
    auto* casted = dynamic_cast<Wider<hoa::Wider<hoa::Hoa3d, float>>*>(wider3D.get());
    EXPECT_THAT(casted, NotNull());
}

TEST(UnitTest_Factory, createOptimMaxRe2D)
{
    auto&& optimMaxRe2D = Factory().createOptimMaxRe2D(3);

    ASSERT_THAT(optimMaxRe2D, NotNull());
    auto* casted = dynamic_cast<Optim<hoa::Optim<hoa::Hoa2d, float>::MaxRe>*>(optimMaxRe2D.get());
    EXPECT_THAT(casted, NotNull());
}

TEST(UnitTest_Factory, createOptimMaxRe3D)
{
    auto&& optimMaxRe3D = Factory().createOptimMaxRe3D(3);

    ASSERT_THAT(optimMaxRe3D, NotNull());
    auto* casted = dynamic_cast<Optim<hoa::Optim<hoa::Hoa3d, float>::MaxRe>*>(optimMaxRe3D.get());
    EXPECT_THAT(casted, NotNull());
}

TEST(UnitTest_Factory, createOptimInPhase2D)
{
    auto&& optimInPhase2D = Factory().createOptimInPhase2D(3);

    ASSERT_THAT(optimInPhase2D, NotNull());
    auto* casted = dynamic_cast<Optim<hoa::Optim<hoa::Hoa2d, float>::InPhase>*>(optimInPhase2D.get());
    EXPECT_THAT(casted, NotNull());
}

TEST(UnitTest_Factory, createOptimInPhase3D)
{
    auto&& optimInPhase3D = Factory().createOptimInPhase3D(3);

    ASSERT_THAT(optimInPhase3D, NotNull());
    auto* casted = dynamic_cast<Optim<hoa::Optim<hoa::Hoa3d, float>::InPhase>*>(optimInPhase3D.get());
    EXPECT_THAT(casted, NotNull());
}

TEST(UnitTest_Factory, createDecoder2D)
{
    auto&& decorder2D = Factory().createDecoder2D(3, std::vector<float>());

    ASSERT_THAT(decorder2D, NotNull());
    auto* casted = dynamic_cast<Decoder<hoa::Decoder<hoa::Hoa2d, float>::Regular>*>(decorder2D.get());
    EXPECT_THAT(casted, NotNull());
}

TEST(UnitTest_Factory, createDecoder3D)
{
    auto&& decorder3D = Factory().createDecoder3D(3, std::vector<float>());

    ASSERT_THAT(decorder3D, NotNull());
    auto* casted = dynamic_cast<Decoder<hoa::Decoder<hoa::Hoa3d, float>::Regular>*>(decorder3D.get());
    EXPECT_THAT(casted, NotNull());
}

TEST(UnitTest_Factory, createPipeline)
{
    auto&& pipeline = Factory().createPipeline(PipelineProperty());
    ASSERT_THAT(pipeline, NotNull());
    EXPECT_THAT(pipeline.get(), WhenDynamicCastTo<Pipeline*>(NotNull()));
}