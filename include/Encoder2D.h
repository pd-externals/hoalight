#pragma once

#include <Hoa.hpp>
#include "IEncoder.h"

class Encoder2D : public IEncoder
{
public:
    explicit Encoder2D(size_t order);

    ~Encoder2D() = default;

    void setRadius(float radius) override;

    void setAzimuth(float azimuth) override;

    void setElevation(float elevation) override;

    std::vector<float> process() override;
private:
    hoa::Encoder<hoa::Dimension::Hoa2d, float> hoaEncoder_;

    std::vector<float> output_;
};
