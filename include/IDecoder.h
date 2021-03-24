#pragma once
#include <memory>
#include <vector>

class IDecoder
{
public:
    virtual ~IDecoder() = default;

    virtual std::vector<float> decode(const std::vector<float>& encodedSample) = 0;

    virtual size_t getNumberOfSpeakers();
};


using DecoderPtr = std::unique_ptr<IDecoder>;
