#pragma once
#include <memory>

class IDecoder
{
public:
    virtual ~IDecoder() = default;

    virtual setSpeakerPosition

    virtual std::vector<float> decode()  = 0;
};

using DecoderPtr = std::unique_ptr<IDecoder>;