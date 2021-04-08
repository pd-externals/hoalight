#pragma once

class IProcessor
{
public:
    virtual ~IProcessor() = default;

    virtual std::vector<float> process(const std::vector<float>& input) = 0;
};
