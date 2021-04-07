#include "HoaLight.h"

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

bool HoaLight::setOrder(float order)
{
    if(positions_.empty())
        return false;

    auto intOrder = static_cast<int>(order);
    order_ = std::clamp(intOrder, 1, 16);
    updateCore();
    return true;
}

bool HoaLight::defineSpeakers(const std::vector<float>& defineSpeakers)
{
    if(defineSpeakers.size() < 2)
        return false;

    const auto dimension = validateDimension(defineSpeakers[0]);
    if(dimension == Dimension::Unknown)
        return false;

    dimension_ = dimension;
    positions_ = std::vector(defineSpeakers.begin() + 1, defineSpeakers.end());
    updateCore();
    return true;
}

bool HoaLight::setAzimuth(float azimuth)
{
    if(!encoder_)
        return false;

    encoder_->setAzimuth(azimuth);
    return true;
}

bool HoaLight::setElevation(float elevation)
{
    if(!encoder_)
        return false;

    encoder_->setElevation(elevation);
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

void HoaLight::updateCore()
{
    encoder_ = factory_->createEncoder(dimension_, order_);
    decoder_ = factory_->createDecoder(dimension_, order_, positions_);
}
