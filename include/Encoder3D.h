#pragma once

#include <Hoa.hpp>
#include "IEncoder.h"

class Encoder3D : public IEncoder
{
public:
    explicit Encoder3D(size_t order);

    ~Encoder3D() = default;

    void setRadius(float radius) override;

    void setAzimuth(float azimuth) override;

    void setElevation(float elevation) override;

    std::vector<float> process() override;
};