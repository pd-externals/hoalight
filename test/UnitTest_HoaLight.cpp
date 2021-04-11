#include <gmock/gmock.h>
#include <HoaLight.h>

#include "PipelineMock.h"
#include "FactoryMock.h"

using namespace testing;

class UnitTest_HoaLight : public ::testing::Test
{
protected:
    void SetUp() override
    {
        factoryMock_ = std::make_unique<NiceMock<FactoryMock>>();
        speakerDefinitions_ = std::vector<float>{2.f, 60.f, 120.f, -120.f, -60.f};

        ON_CALL(*factoryMock_, createPipeline(_))
          .WillByDefault(Invoke([&](const PipelineProperty& property){
              auto&& pipelineMock =  std::make_unique<NiceMock<PipelineMock>>();
              pipelineMockPtr_ = pipelineMock.get();
              return std::move(pipelineMock);
          }));
    }

    void TearDown() override
    {
        factoryMock_ = nullptr;
    }

    std::unique_ptr<FactoryMock> factoryMock_;
    std::vector<float> speakerDefinitions_;

    PipelineMock* pipelineMockPtr_;
};

TEST_F(UnitTest_HoaLight, setOrder)
{
    EXPECT_CALL(*factoryMock_, createPipeline(_)).Times(0);

    auto&& hoaLight = HoaLight(std::move(factoryMock_));
    hoaLight.setOrder(5);
}

TEST_F(UnitTest_HoaLight, setOrder_pipeline_ready)
{
    EXPECT_CALL(*factoryMock_, createPipeline(_)).Times(2);

    auto&& hoaLight = HoaLight(std::move(factoryMock_));
    hoaLight.defineSpeakers(speakerDefinitions_);
    hoaLight.setOrder(5);
}

TEST_F(UnitTest_HoaLight, defineSpeakers)
{
    EXPECT_CALL(*factoryMock_, createPipeline(_)).Times(1);

    auto&& hoaLight = HoaLight(std::move(factoryMock_));
    hoaLight.defineSpeakers(speakerDefinitions_);
}

TEST_F(UnitTest_HoaLight, setAzimuth)
{
    auto&& hoaLight = HoaLight(std::move(factoryMock_));
    hoaLight.defineSpeakers(speakerDefinitions_);

    EXPECT_CALL(*pipelineMockPtr_, setAzimuth(50.f));
    hoaLight.setAzimuth(50.f);
}

TEST_F(UnitTest_HoaLight, setElevation)
{
    auto&& hoaLight = HoaLight(std::move(factoryMock_));
    hoaLight.defineSpeakers(speakerDefinitions_);

    EXPECT_CALL(*pipelineMockPtr_, setElevation(50.f));
    hoaLight.setElevation(50.f);
}

TEST_F(UnitTest_HoaLight, setRadius)
{
    auto&& hoaLight = HoaLight(std::move(factoryMock_));
    hoaLight.defineSpeakers(speakerDefinitions_);

    EXPECT_CALL(*pipelineMockPtr_, setRadius(5.f));
    hoaLight.setRadius(5.f);
}

TEST_F(UnitTest_HoaLight, setOptim)
{
    EXPECT_CALL(*factoryMock_, createPipeline(_)).Times(0);

    auto&& hoaLight = HoaLight(std::move(factoryMock_));
    hoaLight.setOptim(OptimType::MaxRe);
}

TEST_F(UnitTest_HoaLight, setOptim_pipeline_ready)
{
    EXPECT_CALL(*factoryMock_, createPipeline(_)).Times(2);

    auto&& hoaLight = HoaLight(std::move(factoryMock_));
    hoaLight.defineSpeakers(speakerDefinitions_);
    hoaLight.setOptim(OptimType::MaxRe);
}

TEST_F(UnitTest_HoaLight, getAmplitude)
{
    auto&& hoaLight = HoaLight(std::move(factoryMock_));
    hoaLight.defineSpeakers(speakerDefinitions_);

    EXPECT_CALL(*pipelineMockPtr_, process()).Times(1);

    hoaLight.getAmplitudes();
}

TEST_F(UnitTest_HoaLight, getNumberOfSpeakers)
{
    auto&& hoaLight = HoaLight(std::move(factoryMock_));
    hoaLight.defineSpeakers(speakerDefinitions_);

    EXPECT_CALL(*pipelineMockPtr_, getNumberOfSpeakers()).Times(1);

    hoaLight.getNumberOfSpeakers();
}

TEST_F(UnitTest_HoaLight, isPrepared_unprepared)
{
    auto&& hoaLight = HoaLight(std::move(factoryMock_));

    EXPECT_FALSE(hoaLight.isPrepared());
}

TEST_F(UnitTest_HoaLight, isPrepared_prepared)
{
    auto&& hoaLight = HoaLight(std::move(factoryMock_));
    hoaLight.defineSpeakers(speakerDefinitions_);

    EXPECT_TRUE(hoaLight.isPrepared());
}