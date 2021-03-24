#include "Encoder.h"

Encoder::Encoder(Dimension dimension, size_t order, const IFactory& factory)
: hoaEncoder_(dimension == Dimension::TWO ? factory.createEncoder2D(order) : factory.createEncoder3D(order))
{
}

void Encoder::setRadius(float radius)
{
    hoaEncoder_->setRadius(radius);
}

void Encoder::setAzimuth(float azimuth)
{
    hoaEncoder_->setAzimuth(azimuth);
}

void Encoder::setElevation(float elevation)
{
    hoaEncoder_->setElevation(elevation);
}

std::vector<float> Encoder::encode()
{
    return hoaEncoder_->encode();
}
