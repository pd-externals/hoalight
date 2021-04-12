#include <gmock/gmock.h>
#include <Pipeline.h>

#include "FactoryMock.h"
#include "DecoderMock.h"
#include "WiderMock.h"
#include "ProcessorMock.h"
#include "EncoderMock.h"

using namespace testing;

class UnitTest_Pipeline : public ::testing::Test
{
protected:
    void SetUp() override
    {
        encoderMock_ = std::make_unique<NiceMock<EncoderMock>>();
        widerMock_ = std::make_unique<NiceMock<WiderMock>>();
        optimMock_ = std::make_unique<NiceMock<ProcessorMock>>();
        decoderMock_ = std::make_unique<NiceMock<DecoderMock>>();

        encoderMockPtr_ = encoderMock_.get();
        widerMockPtr_ = widerMock_.get();
        optimMockPtr_ = optimMock_.get();
        decoderMockPtr_ = decoderMock_.get();

        ON_CALL(factoryMock_, createEncoder3D(_))
                .WillByDefault(Return(ByMove(std::move(encoderMock_))));
        ON_CALL(factoryMock_, createWider3D(_))
                .WillByDefault(Return(ByMove(std::move(widerMock_))));
        ON_CALL(factoryMock_, createOptimMaxRe3D(_))
                .WillByDefault(Return(ByMove(std::move(optimMock_))));
        ON_CALL(factoryMock_, createDecoder3D(_, _))
                .WillByDefault(Return(ByMove(std::move(decoderMock_))));
    }

    void TearDown() override
    {
        encoderMock_ = nullptr;
        widerMock_ = nullptr;
        optimMock_ = nullptr;
        decoderMock_ = nullptr;
    }

    NiceMock<FactoryMock> factoryMock_;
    std::unique_ptr<EncoderMock> encoderMock_;
    std::unique_ptr<WiderMock> widerMock_;
    std::unique_ptr<ProcessorMock> optimMock_;
    std::unique_ptr<DecoderMock> decoderMock_;

    EncoderMock* encoderMockPtr_;
    WiderMock* widerMockPtr_;
    ProcessorMock* optimMockPtr_;
    DecoderMock* decoderMockPtr_;
};

TEST_F(UnitTest_Pipeline, construction_throws_unknown_dimension)
{
    auto&& pp = PipelineProperty {Dimension::Unknown, std::vector<float>{30.f}, 1, OptimType::None};
    EXPECT_THROW(Pipeline(pp, factoryMock_), std::invalid_argument);
}

TEST_F(UnitTest_Pipeline, construction_throws_too_few_speakers)
{
    auto&& pp = PipelineProperty {Dimension::Two, std::vector<float>{}, 1, OptimType::None};
    EXPECT_THROW(Pipeline(pp, factoryMock_), std::invalid_argument);
}

TEST_F(UnitTest_Pipeline, construction_2D)
{
    EXPECT_CALL(factoryMock_, createEncoder2D(1)).Times(1);
    EXPECT_CALL(factoryMock_, createWider2D(1)).Times(1);
    EXPECT_CALL(factoryMock_, createDecoder2D(1, _)).Times(1);

    auto&& pp = PipelineProperty {Dimension::Two, std::vector<float>{30.f}, 1, OptimType::None};
    Pipeline(pp, factoryMock_);
}

TEST_F(UnitTest_Pipeline, construction_3D)
{
    EXPECT_CALL(factoryMock_, createEncoder3D(1)).Times(1);
    EXPECT_CALL(factoryMock_, createWider3D(1)).Times(1);
    EXPECT_CALL(factoryMock_, createDecoder3D(1, _)).Times(1);

    auto&& pp = PipelineProperty {Dimension::Three, std::vector<float>{30.f}, 1, OptimType::None};
    Pipeline(pp, factoryMock_);
}

TEST_F(UnitTest_Pipeline, optimMaxRe2D)
{
    EXPECT_CALL(factoryMock_, createOptimMaxRe2D(1)).Times(1);

    Pipeline(PipelineProperty {Dimension::Two, std::vector<float>{30.f}, 1, OptimType::MaxRe}, factoryMock_);
}

TEST_F(UnitTest_Pipeline, optimMaxRe3D)
{
    EXPECT_CALL(factoryMock_, createOptimMaxRe3D(1)).Times(1);

    Pipeline(PipelineProperty {Dimension::Three, std::vector<float>{30.f}, 1, OptimType::MaxRe}, factoryMock_);
}

TEST_F(UnitTest_Pipeline, optimInPhase2D)
{
    EXPECT_CALL(factoryMock_, createOptimInPhase2D(1)).Times(1);

    Pipeline(PipelineProperty {Dimension::Two, std::vector<float>{30.f}, 1, OptimType::InPhase}, factoryMock_);
}

TEST_F(UnitTest_Pipeline, optimInPhase3D)
{
    EXPECT_CALL(factoryMock_, createOptimInPhase3D(1)).Times(1);

    Pipeline(PipelineProperty {Dimension::Three, std::vector<float>{30.f}, 1, OptimType::InPhase}, factoryMock_);
}

TEST_F(UnitTest_Pipeline, process)
{
    {
        InSequence seq;
        EXPECT_CALL(*encoderMockPtr_, process());
        EXPECT_CALL(*widerMockPtr_, process(_));
        EXPECT_CALL(*decoderMockPtr_, process(_));
    }

    auto&& pp = PipelineProperty {Dimension::Three, std::vector<float>{30.f, 30.f}, 1, OptimType::None};
    auto&& pipeline = Pipeline(pp, factoryMock_);
    pipeline.process();
}

TEST_F(UnitTest_Pipeline, process_with_optim)
{
    {
        InSequence seq;
        EXPECT_CALL(*encoderMockPtr_, process());
        EXPECT_CALL(*widerMockPtr_, process(_));
        EXPECT_CALL(*optimMockPtr_, process(_));
        EXPECT_CALL(*decoderMockPtr_, process(_));
    }

    auto&& pp = PipelineProperty {Dimension::Three, std::vector<float>{30.f, 30.f}, 1, OptimType::MaxRe};
    auto&& pipeline = Pipeline(pp, factoryMock_);
    pipeline.process();
}

TEST_F(UnitTest_Pipeline, setAzimuth)
{
    EXPECT_CALL(*encoderMockPtr_, setAzimuth(50.f)).Times(1);

    auto&& pp = PipelineProperty {Dimension::Three, std::vector<float>{30.f, 30.f}, 1, OptimType::MaxRe};
    auto&& pipeline = Pipeline(pp, factoryMock_);
    pipeline.setAzimuth(50.f);
}

TEST_F(UnitTest_Pipeline, setElevation)
{
    EXPECT_CALL(*encoderMockPtr_, setElevation(40.f)).Times(1);

    auto&& pp = PipelineProperty {Dimension::Three, std::vector<float>{30.f, 30.f}, 1, OptimType::MaxRe};
    auto&& pipeline = Pipeline(pp, factoryMock_);
    pipeline.setElevation(40.f);
}

TEST_F(UnitTest_Pipeline, setRadius)
{
    EXPECT_CALL(*widerMockPtr_, setWidening(30.f)).Times(1);

    auto&& pp = PipelineProperty {Dimension::Three, std::vector<float>{30.f, 30.f}, 1, OptimType::MaxRe};
    auto&& pipeline = Pipeline(pp, factoryMock_);
    pipeline.setRadius(30.f);
}

TEST_F(UnitTest_Pipeline, getNumberOfSpeakers)
{
    EXPECT_CALL(*decoderMockPtr_, getNumberOfSpeakers()).Times(1);

    auto&& pp = PipelineProperty {Dimension::Three, std::vector<float>{30.f, 30.f}, 1, OptimType::MaxRe};
    auto&& pipeline = Pipeline(pp, factoryMock_);
    pipeline.getNumberOfSpeakers();
}