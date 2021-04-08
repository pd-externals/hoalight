#include <gmock/gmock.h>
#include <Encoder.h>
#include <Blauert.h>

#include "EncoderMock.h"
#include "FactoryMock.h"

using namespace testing;

class UnitTest_Encoder : public ::testing::Test
{
protected:
    void SetUp() override
    {
        encoderMock_ = std::make_unique<EncoderMock>();
        encoderMockPtr_ = encoderMock_.get();

        ON_CALL(factoryMock_, createEncoder3D(_)).WillByDefault(Return(ByMove(std::move(encoderMock_))));
    }

    void TearDown() override
    {
        encoderMock_ = nullptr;
    }

    std::unique_ptr<EncoderMock> encoderMock_;
    NiceMock<FactoryMock> factoryMock_;

    EncoderMock* encoderMockPtr_;

};

TEST_F(UnitTest_Encoder, construction_two_dimension)
{
    EXPECT_CALL(factoryMock_, createEncoder2D(3));

    Encoder(Dimension::Two, 3, factoryMock_);
}

TEST_F(UnitTest_Encoder, construction_three_dimension)
{
    EXPECT_CALL(factoryMock_, createEncoder3D(3));

    Encoder(Dimension::Three, 3, factoryMock_);
}

TEST_F(UnitTest_Encoder, setRadius_radius_100)
{
    EXPECT_CALL(*encoderMockPtr_, setRadius(0.0f));

    auto&& encoder = Encoder(Dimension::Three, 3, factoryMock_);
    encoder.setRadius(100.0f);
}

TEST_F(UnitTest_Encoder, setRadius_raidus_0)
{
    EXPECT_CALL(*encoderMockPtr_, setRadius(1.0f));

    auto&& encoder = Encoder(Dimension::Three, 3, factoryMock_);
    encoder.setRadius(0.0f);
}

TEST_F(UnitTest_Encoder, setRadius_negative)
{
    EXPECT_CALL(*encoderMockPtr_, setRadius(1.0f));

    auto&& encoder = Encoder(Dimension::Three, 3, factoryMock_);
    encoder.setRadius(-0.01f);
}

TEST_F(UnitTest_Encoder, setRadius_exceeds_100)
{
    EXPECT_CALL(*encoderMockPtr_, setRadius(0.0f));

    auto&& encoder = Encoder(Dimension::Three, 3, factoryMock_);
    encoder.setRadius(100.1f);
}

TEST_F(UnitTest_Encoder, setAzimuth)
{
    EXPECT_CALL(*encoderMockPtr_, setAzimuth(Blauert::toPhi(45.0f)));

    auto&& encoder = Encoder(Dimension::Three, 3, factoryMock_);
    encoder.setAzimuth(45.0f);
}

TEST_F(UnitTest_Encoder, setElevation)
{
    EXPECT_CALL(*encoderMockPtr_, setElevation(Blauert::toTheta(30.0f)));

    auto&& encoder = Encoder(Dimension::Three, 3, factoryMock_);
    encoder.setElevation(30.0f);
}

TEST_F(UnitTest_Encoder, process)
{
    EXPECT_CALL(*encoderMockPtr_, encode);

    auto&& encoder = Encoder(Dimension::Three, 3, factoryMock_);
    encoder.process();
}
