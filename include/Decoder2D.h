#pragma once

#include "IDecoder.h"
#include "Hoa_Decoder.hpp"

class Decoder2D : public IDecoder
{
public:
    Decoder2D(size_t order, const std::vector<float>& positions);

    ~Decoder2D() override = default;

    std::vector<float> decode(const std::vector<float>& encodedSample) override;

    size_t getNumberOfSpeakers() const override;

private:
    hoa::DecoderRegular<hoa::Dimension::Hoa2d, float> hoaDecoder_;

    std::vector<float> output_;
};