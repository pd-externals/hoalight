#include "Encoder.h"
#include "Blauert.h"
#include <algorithm>

Encoder::Encoder(Dimension dimension, size_t order, const IFactory& factory)
: hoaEncoder_(dimension == Dimension::Two ? factory.createEncoder2D(order) : factory.createEncoder3D(order))
{
}

void Encoder::setRadius(float radius)
{
    const auto clamped = std::clamp(radius, 0.f, 100.f);
    hoaEncoder_->setRadius((100.f - clamped)/ 100.f);
}

void Encoder::setAzimuth(float azimuth)
{
    const auto phi = Blauert::toPhi(azimuth);
    hoaEncoder_->setAzimuth(phi);
}

void Encoder::setElevation(float elevation)
{
    const auto theta = Blauert::toPhi(elevation);
    hoaEncoder_->setElevation(theta);
}

std::vector<float> Encoder::encode()
{
    return hoaEncoder_->encode();
}
