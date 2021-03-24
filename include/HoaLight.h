#pragma once

#include <vector>
#include <IEncoder.h>
#include <IDecoder.h>

class HoaLight
{
public:

    bool setAzimuth(float azimuth);

    bool setElevation(float elevation);

    bool setRadius(float radius);

    bool setSpeakers(const std::vector<float>& speakers);

    std::vector<float> getAmplitude() const;

private:

    EncoderPtr encoderPtr_;


};
