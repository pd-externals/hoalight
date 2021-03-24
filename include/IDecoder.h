#pragma once
#include <memory>

class IDecoder
{
public:
    virtual ~IDecoder() = default;

};

using DecoderPtr = std::unique_ptr<IDecoder>;