#include "HoaLight.h"
#include "Blauert.h"

bool HoaLight::setSpeakers(const std::vector<float>& speakers)
{

}

bool HoaLight::setAzimuth(float azimuth)
{
    if(encoderPtr_)
        return false;

    auto phi = Blauert::toPhi(azimuth);
    encoderPtr_->setAzimuth(phi);
    return true;
}

bool HoaLight::setElevation(float elevation)
{
    if(encoderPtr_)
        return false;

    auto theta = Blauert::toPhi(elevation);
    encoderPtr_->setElevation(theta);
    return true;
}

bool HoaLight::setRadius(float radius)
{
    if(encoderPtr_)
        return false;
    encoderPtr_->setRadius(radius);
    return true;
}

std::vector<float> HoaLight::getAmplitude() const
{
    return std::vector<float>();
}
