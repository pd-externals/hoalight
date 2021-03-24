#include <gmock/gmock.h>
#include <HoaLight.h>

#include "FactoryMock.h"
#include "DecoderMock.h"
#include "EncoderMock.h"

using namespace testing;

class UnitTest_HoaLight : public ::testing::Test
{
protected:
    void SetUp() override
    {
        factoryMock_ = std::make_unique<NiceMock<FactoryMock>>();
        encoderMock_ = std::make_unique<NiceMock<EncoderMock>>();
        decoderMock_ = std::make_unique<NiceMock<DecoderMock>>();

        factoryMockPtr_ = factoryMock_.get();
        encoderMockPtr_ = encoderMock_.get();
        decoderMockPtr_ = decoderMock_.get();

        ON_CALL(*factoryMock_, createEncoder(_, _))
                .WillByDefault(Return(ByMove(std::move(encoderMock_))));
        ON_CALL(*factoryMock_, createDecoder(_, _, _))
                .WillByDefault(Return(ByMove(std::move(decoderMock_))));
    }

    void TearDown() override
    {
        factoryMock_ = nullptr;
        encoderMock_ = nullptr;
        decoderMock_ = nullptr;
    }

    std::unique_ptr<FactoryMock> factoryMock_;
    std::unique_ptr<EncoderMock> encoderMock_;
    std::unique_ptr<DecoderMock> decoderMock_;

    FactoryMock* factoryMockPtr_;
    EncoderMock* encoderMockPtr_;
    DecoderMock* decoderMockPtr_;

    std::vector<float> positions_;
};

TEST_F(UnitTest_HoaLight, setSpeakers_zero_speakers)
{
    EXPECT_CALL(*factoryMock_, createEncoder(_, _)).Times(0);
    EXPECT_CALL(*factoryMock_, createDecoder(_, _, _)).Times(0);

    auto hoaLight = HoaLight(std::move(factoryMock_));
    auto defineSpeakers = std::vector<float>{};
    auto result = hoaLight.defineSpeakers(defineSpeakers);

    EXPECT_FALSE(result);
}

TEST_F(UnitTest_HoaLight, setSpeakers_insufficient_number_of_speakers)
{
    EXPECT_CALL(*factoryMock_, createEncoder(_, _)).Times(0);
    EXPECT_CALL(*factoryMock_, createDecoder(_, _, _)).Times(0);

    auto hoaLight = HoaLight(std::move(factoryMock_));
    auto defineSpeakers = std::vector<float>{2};
    auto result = hoaLight.defineSpeakers(defineSpeakers);

    EXPECT_FALSE(result);
}

TEST_F(UnitTest_HoaLight, setSpeakers_unknown_dimension)
{
    EXPECT_CALL(*factoryMock_, createEncoder(_, _)).Times(0);
    EXPECT_CALL(*factoryMock_, createDecoder(_, _, _)).Times(0);

    auto hoaLight = HoaLight(std::move(factoryMock_));
    auto defineSpeakers = std::vector<float>{1.f, 30.f};
    auto result = hoaLight.defineSpeakers(defineSpeakers);

    EXPECT_FALSE(result);
}

TEST_F(UnitTest_HoaLight, setSpeakers_2D)
{
    EXPECT_CALL(*factoryMock_, createEncoder(Dimension::Two, _)).Times(1);
    EXPECT_CALL(*factoryMock_, createDecoder(Dimension::Two, _, _)).Times(1);

    auto hoaLight = HoaLight(std::move(factoryMock_));
    auto defineSpeakers = std::vector<float>{2.f, 0.f, 90.f, 180.f, -90.f};
    auto result = hoaLight.defineSpeakers(defineSpeakers);

    EXPECT_TRUE(result);
}

TEST_F(UnitTest_HoaLight, setSpeakers_3D)
{
    EXPECT_CALL(*factoryMock_, createEncoder(Dimension::Three, _)).Times(1);
    EXPECT_CALL(*factoryMock_, createDecoder(Dimension::Three, _, _)).Times(1);

    auto hoaLight = HoaLight(std::move(factoryMock_));
    auto defineSpeakers = std::vector<float>{3.f, 0.f, 30.f, 0.f, -30.f};
    auto result = hoaLight.defineSpeakers(defineSpeakers);

    EXPECT_TRUE(result);
}

TEST_F(UnitTest_HoaLight, setOrder)
{
    EXPECT_CALL(*factoryMock_, createEncoder(_, 3)).Times(1);
    EXPECT_CALL(*factoryMock_, createDecoder(_, 3, _)).Times(1);

    auto hoaLight = HoaLight(std::move(factoryMock_));
    hoaLight.setOrder(3.f);
    auto defineSpeakers = std::vector<float>{3.f, 0.f, 30.f, 0.f, -30.f};
    auto result = hoaLight.defineSpeakers(defineSpeakers);

    EXPECT_TRUE(result);
}

TEST_F(UnitTest_HoaLight, setAzimuth)
{
    EXPECT_CALL(*encoderMockPtr_, setAzimuth(0.f)).Times(1);

    auto hoaLight = HoaLight(std::move(factoryMock_));
    auto defineSpeakers = std::vector<float>{2.f, 0.f, 90.f, 180.f, -90.f};
    hoaLight.defineSpeakers(defineSpeakers);

    EXPECT_TRUE(hoaLight.setAzimuth(90.f));
}

TEST_F(UnitTest_HoaLight, setAzimuth_invalid)
{
    EXPECT_CALL(*encoderMockPtr_, setAzimuth(_)).Times(0);

    auto hoaLight = HoaLight(std::move(factoryMock_));

    EXPECT_FALSE(hoaLight.setAzimuth(90.f));
}

TEST_F(UnitTest_HoaLight, setElevation)
{
    EXPECT_CALL(*encoderMockPtr_, setElevation(0.f)).Times(1);

    auto hoaLight = HoaLight(std::move(factoryMock_));
    auto defineSpeakers = std::vector<float>{3.f, 0.f, 30.f, 0.f, -30.f};
    hoaLight.defineSpeakers(defineSpeakers);

    EXPECT_TRUE(hoaLight.setElevation(90.f));
}

TEST_F(UnitTest_HoaLight, setElevation_invalid)
{
    EXPECT_CALL(*encoderMockPtr_, setElevation(_)).Times(0);

    auto hoaLight = HoaLight(std::move(factoryMock_));

    EXPECT_FALSE(hoaLight.setElevation(90.f));
}

TEST_F(UnitTest_HoaLight, setRadius)
{
    EXPECT_CALL(*encoderMockPtr_, setRadius(2.f)).Times(1);

    auto hoaLight = HoaLight(std::move(factoryMock_));
    auto defineSpeakers = std::vector<float>{3.f, 0.f, 30.f, 0.f, -30.f};
    hoaLight.defineSpeakers(defineSpeakers);

    EXPECT_TRUE(hoaLight.setRadius(2.f));
}

TEST_F(UnitTest_HoaLight, setRadius_invalid)
{
    EXPECT_CALL(*encoderMockPtr_, setRadius(_)).Times(0);

    auto hoaLight = HoaLight(std::move(factoryMock_));

    EXPECT_FALSE(hoaLight.setElevation(2.f));
}

TEST_F(UnitTest_HoaLight, getAmplitudes)
{
    {
        InSequence seq;
        EXPECT_CALL(*encoderMockPtr_, encode()).Times(1);
        EXPECT_CALL(*decoderMockPtr_, decode(_)).Times(1);
    }

    auto hoaLight = HoaLight(std::move(factoryMock_));
    auto defineSpeakers = std::vector<float>{3.f, 0.f, 30.f, 0.f, -30.f};
    hoaLight.defineSpeakers(defineSpeakers);
    hoaLight.getAmplitudes();
}

TEST_F(UnitTest_HoaLight, getAmplitudes_invalid)
{
    EXPECT_CALL(*encoderMockPtr_, encode()).Times(0);
    EXPECT_CALL(*decoderMockPtr_, decode(_)).Times(0);

    auto hoaLight = HoaLight(std::move(factoryMock_));
    auto result = hoaLight.getAmplitudes();

    EXPECT_EQ(0, result.size());
}
