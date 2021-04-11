#pragma once
#include <gmock/gmock.h>
#include <IProcessor.h>

class ProcessorMock : public IProcessor {

public:
    ~ProcessorMock() = default;

    MOCK_METHOD0(process, std::vector<float>());
};
