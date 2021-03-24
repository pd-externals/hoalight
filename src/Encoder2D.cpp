#include "Encoder2D.h"

Encoder2D::Encoder2D(size_t order)
: hoaEncoder_(order)
{
    const auto numHarmonics = (order+1) * (order+1);
    output_.resize(numHarmonics);
}

void Encoder2D::setRadius(float radius)
{
    hoaEncoder_.setRadius(radius);
}

void Encoder2D::setAzimuth(float azimuth)
{
    hoaEncoder_.setAzimuth(azimuth);
}

void Encoder2D::setElevation(float elevation)
{
    // no operation
}

std::vector<float> Encoder2D::process()
{
    const static auto input = 1.f;
    hoaEncoder_.process(&input, output_.data());
    return output_;
}
