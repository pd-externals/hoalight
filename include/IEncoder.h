#pragma once
#include <vector>

class IEncoder
{
public:

    virtual ~IEncoder() = default;

    virtual void setAzimuth(float azimuth) = 0;

    virtual void setElevation(float elevation) = 0;

    virtual std::vector<float> process() = 0;
};

using EncoderPtr = std::unique_ptr<IEncoder>;