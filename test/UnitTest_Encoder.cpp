#include <gmock/gmock.h>
#include <Encoder.h>

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

    Encoder(Dimension::TWO, 3, factoryMock_);
}

TEST_F(UnitTest_Encoder, construction_three_dimension)
{
    EXPECT_CALL(factoryMock_, createEncoder3D(3));

    Encoder(Dimension::THREE, 3, factoryMock_);
}

TEST_F(UnitTest_Encoder, setRadius)
{
    EXPECT_CALL(*encoderMockPtr_, setRadius(3.0f));

    auto&& encoder = Encoder(Dimension::THREE, 3, factoryMock_);
    encoder.setRadius(3.0f);
}

TEST_F(UnitTest_Encoder, setAzimuth)
{
    EXPECT_CALL(*encoderMockPtr_, setAzimuth(45.0f));

    auto&& encoder = Encoder(Dimension::THREE, 3, factoryMock_);
    encoder.setAzimuth(45.0f);
}

TEST_F(UnitTest_Encoder, setElevation)
{
    EXPECT_CALL(*encoderMockPtr_, setElevation(30.0f));

    auto&& encoder = Encoder(Dimension::THREE, 3, factoryMock_);
    encoder.setElevation(30.0f);
}

TEST_F(UnitTest_Encoder, process)
{
    EXPECT_CALL(*encoderMockPtr_, process);

    auto&& encoder = Encoder(Dimension::THREE, 3, factoryMock_);
    encoder.process();
}
