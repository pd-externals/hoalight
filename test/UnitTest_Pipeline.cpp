#include <gmock/gmock.h>
#include <HoaLight.h>

#include "FactoryMock.h"
#include "DecoderMock.h"
#include "WiderMock.h"
#include "ProcessorMock.h"
#include "EncoderMock.h"

using namespace testing;

class UnitTest_HoaLight : public ::testing::Test
{
protected:
    void SetUp() override
    {
        factoryMock_ = std::make_unique<NiceMock<FactoryMock>>();
        encoderMock_ = std::make_unique<NiceMock<EncoderMock>>();
        widerMock_ = std::make_unique<NiceMock<WiderMock>>();
        optimMock_ = std::make_unique<NiceMock<ProcessorMock>>();
        decoderMock_ = std::make_unique<NiceMock<DecoderMock>>();

        encoderMockPtr_ = encoderMock_.get();
        widerMockPtr_ = widerMock_.get();
        optimMockPtr_ = optimMock_.get();
        decoderMockPtr_ = decoderMock_.get();

        ON_CALL(*factoryMock_, createEncoder2D(_))
                .WillByDefault(Return(ByMove(std::move(encoderMock_))));
        ON_CALL(*factoryMock_, createEncoder3D(_))
                .WillByDefault(Return(ByMove(std::move(encoderMock_))));
        ON_CALL(*factoryMock_, createWider2D(_))
                .WillByDefault(Return(ByMove(std::move(widerMock_))));
        ON_CALL(*factoryMock_, createWider3D(_))
                .WillByDefault(Return(ByMove(std::move(widerMock_))));
        ON_CALL(*factoryMock_, createOptimMaxRe2D(_))
                .WillByDefault(Return(ByMove(std::move(optimMock_))));
        ON_CALL(*factoryMock_, createOptimMaxRe3D(_))
                .WillByDefault(Return(ByMove(std::move(optimMock_))));
        ON_CALL(*factoryMock_, createOptimInPhase2D(_))
                .WillByDefault(Return(ByMove(std::move(optimMock_))));
        ON_CALL(*factoryMock_, createOptimInPhase3D(_))
                .WillByDefault(Return(ByMove(std::move(optimMock_))));
        MOCK_CONST_METHOD2(createDecoder2D, DecoderPtr(size_t order, const std::vector<float>& positions));

        MOCK_CONST_METHOD2(createDecoder3D, DecoderPtr(size_t order, const std::vector<float>& positions));

    }

    void TearDown() override
    {
        factoryMock_ = nullptr;
        encoderMock_ = nullptr;
        widerMock_ = nullptr;
        optimMock_ = nullptr;
        decoderMock_ = nullptr;
    }

    std::unique_ptr<FactoryMock> factoryMock_;
    std::unique_ptr<EncoderMock> encoderMock_;
    std::unique_ptr<WiderMock> widerMock_;
    std::unique_ptr<ProcessorMock> optimMock_;
    std::unique_ptr<DecoderMock> decoderMock_;


    EncoderMock* encoderMockPtr_;
    WiderMock* widerMockPtr_;
    ProcessorMock* optimMockPtr_;
    DecoderMock* decoderMockPtr_;
};
