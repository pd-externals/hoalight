#include "HoaLight.h"
#include "Blauert.h"

namespace
{
    Dimension validateDimension(float dimension)
    {
        if (dimension == 2.f)
            return Dimension::Two;
        if (dimension == 3.f)
            return Dimension::Three;
        return Dimension::Unknown;
    }
}

HoaLight::HoaLight(FactoryPtr factory)
: factory_(std::move(factory))
, order_(1)
{}

void HoaLight::setOrder(float order)
{
    auto intOrder = static_cast<int>(order);
    order_ = std::clamp(intOrder, 1, 16);
}

bool HoaLight::defineSpeakers(const std::vector<float>& defineSpeakers)
{
    if(defineSpeakers.size() < 2)
        return false;

    const auto dimension = validateDimension(defineSpeakers[0]);
    if(dimension == Dimension::Unknown)
        return false;

    const auto positions = std::vector(defineSpeakers.begin() + 1, defineSpeakers.end());
    encoder_ = factory_->createEncoder(dimension, order_);
    decoder_ = factory_->createDecoder(dimension, order_, positions);
    return true;
}

bool HoaLight::setAzimuth(float azimuth)
{
    if(!encoder_)
        return false;

    const auto phi = Blauert::toPhi(azimuth);
    encoder_->setAzimuth(phi);
    return true;
}

bool HoaLight::setElevation(float elevation)
{
    if(!encoder_)
        return false;

    const auto theta = Blauert::toPhi(elevation);
    encoder_->setElevation(theta);
    return true;
}

bool HoaLight::setRadius(float radius)
{
    if(!encoder_)
        return false;
    encoder_->setRadius(radius);
    return true;
}

std::vector<float> HoaLight::getAmplitudes() const
{
    if(!encoder_)
        return std::vector<float>();
    return decoder_->decode(encoder_->encode());
}

size_t HoaLight::getNumberOfSpeakers() const
{
    if(!encoder_)
        return 0;
    return decoder_->getNumberOfSpeakers();
}
