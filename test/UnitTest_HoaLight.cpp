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

    }

    void TearDown() override
    {
        factoryMock_ = nullptr;
    }

    std::unique_ptr<FactoryMock> factoryMock_;
};