#pragma once

#include <Hoa.hpp>
#include "IEncoder.h"

class Encoder2D : public IEncoder
{
public:
    explicit Encoder2D(size_t order);

    ~Encoder2D() = default;

    void setAzimuth(float azimuth) override;

    void setElevation(float elevation) override;

    std::vector<float> encode() override;
private:
    hoa::Encoder<hoa::Dimension::Hoa2d, float>::Basic hoaEncoder_;

    std::vector<float> output_;
};
