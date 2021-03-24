#pragma once

#include <Hoa.hpp>
#include "Dimension.h"
#include "IEncoder.h"
#include "IFactory.h"

class Encoder : public IEncoder
{
public:
    Encoder(Dimension dimension, size_t order, const IFactory& factory);

    ~Encoder() = default;

    void setRadius(float radius) override;

    void setAzimuth(float azimuth) override;

    void setElevation(float elevation) override;

    std::vector<float> process() override;

private:
    EncoderPtr hoaEncoder_;
};