#include <gmock/gmock.h>
#include <Decoder.h>

#include "DecoderMock.h"
#include "FactoryMock.h"

using namespace testing;

class UnitTest_Decoder : public ::testing::Test
{
protected:
    void SetUp() override
    {
        decoderMock_ = std::make_unique<NiceMock<DecoderMock>>();
        decoderMockPtr_ = decoderMock_.get();

        ON_CALL(factoryMock_, createDecoder3D(_, _))
           .WillByDefault(Return(ByMove(std::move(decoderMock_))));
    }

    void TearDown() override
    {
        decoderMock_ = nullptr;
    }

    NiceMock<FactoryMock> factoryMock_;
    std::unique_ptr<DecoderMock> decoderMock_;

    DecoderMock* decoderMockPtr_;

    std::vector<float> positions_;
};

TEST_F(UnitTest_Decoder, construction_two_dimension)
{
    EXPECT_CALL(factoryMock_, createDecoder2D(3, positions_));

    Decoder(Dimension::Two, 3, positions_, factoryMock_);
}

TEST_F(UnitTest_Decoder, construction_three_dimension)
{
    EXPECT_CALL(factoryMock_, createDecoder3D(3, positions_));

    Decoder(Dimension::Three, 3, positions_, factoryMock_);
}

TEST_F(UnitTest_Decoder, decode)
{
    auto&& encodedSample = std::vector<float>();
    EXPECT_CALL(*decoderMockPtr_, decode(encodedSample));

    auto&& decoder = Decoder(Dimension::Three, 3, positions_, factoryMock_);
    decoder.decode(encodedSample);
}

TEST_F(UnitTest_Decoder, getNumberOfSpeakers)
{
    ON_CALL(*decoderMockPtr_, getNumberOfSpeakers()).WillByDefault(Return(8));

    auto&& decoder = Decoder(Dimension::Three, 3, positions_, factoryMock_);

    EXPECT_EQ(8, decoder.getNumberOfSpeakers());
}
