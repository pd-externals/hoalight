#pragma once
#include <vector>
#include "IProcessor.h"

class IEncoder
{
public:

    virtual ~IEncoder() = default;

    virtual void setAzimuth(float phi) = 0;

    virtual void setElevation(float theta) = 0;

    virtual std::vector<float> process() = 0;
};

using EncoderPtr = std::unique_ptr<IEncoder>;
