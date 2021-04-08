#pragma once
#include <memory>
#include <vector>

class IDecoder : public IProcessor
{
public:
    virtual ~IDecoder() = default;

    virtual size_t getNumberOfSpeakers() const = 0;
};

using DecoderPtr = std::unique_ptr<IDecoder>;
