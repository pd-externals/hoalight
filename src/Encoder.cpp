#include "Encoder.h"

Encoder::Encoder(Dimension dimension, size_t order, const IFactory& factory)
: core_(dimension == Dimension::TWO ? factory.CreateEncoder2D(order) : factory.CreateEncoder3D(order))
{
}

void Encoder::setRadius(float radius)
{
    core_->setRadius(radius);
}

void Encoder::setAzimuth(float azimuth)
{
    core_->setAzimuth(azimuth);
}

void Encoder::setElevation(float elevation)
{
    core_->setElevation(elevation);
}

std::vector<float> Encoder::process()
{
    return core_->process();
}
