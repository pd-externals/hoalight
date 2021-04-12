#pragma once
#include <gmock/gmock.h>
#include <IProcessor.h>

class ProcessorMock : public IProcessor {

public:
    ~ProcessorMock() = default;

    MOCK_METHOD1(process, std::vector<float>(const std::vector<float>&));
};
