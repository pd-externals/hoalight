#pragma once
#include <memory>

class IProcessor
{
public:
    virtual ~IProcessor() = default;

    virtual std::vector<float> process(const std::vector<float>& input) = 0;
};

using ProcessorPtr = std::unique_ptr<IProcessor>;