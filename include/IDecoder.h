#pragma once
#include <memory>
#include <vector>

class IDecoder
{
public:
    virtual ~IDecoder() = default;

    virtual std::vector<float> decode(const std::vector<float>& bFormat) = 0;

    virtual size_t getNumberOfSpeakers() const = 0;
};

using DecoderPtr = std::unique_ptr<IDecoder>;
