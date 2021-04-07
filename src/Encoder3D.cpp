#include "Encoder3D.h"
#include <Hoa.hpp>

Encoder3D::Encoder3D(size_t order)
: hoaEncoder_(order)
{
    const auto numHarmonics = (order+1) * (order+1);
    output_.resize(numHarmonics);
}

void Encoder3D::setAzimuth(float azimuth)
{
    hoaEncoder_.setAzimuth(azimuth);
}

void Encoder3D::setElevation(float elevation)
{
    hoaEncoder_.setElevation(elevation);
}

std::vector<float> Encoder3D::encode()
{
    const static auto input = 1.f;
    hoaEncoder_.process(&input, output_.data());
    return output_;
}
