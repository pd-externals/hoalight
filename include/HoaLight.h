#pragma once

#include <vector>
#include "IEncoder.h"
#include "IDecoder.h"
#include "IFactory.h"

class HoaLight
{
public:
    HoaLight(FactoryPtr factory);

    void setOrder(float order);

    bool setAzimuth(float azimuth);

    bool setElevation(float elevation);

    bool setRadius(float radius);

    bool setSpeakers(const std::vector<float>& speakers);

    std::vector<float> getAmplitude() const;

private:

    FactoryPtr factory_;
    EncoderPtr encoder_;
    DecoderPtr decoder_;
    size_t order_;
};
