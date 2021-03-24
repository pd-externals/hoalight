#pragma once

#include "IDecoder.h"
#include "Hoa_Decoder.hpp"

class Decoder3D : public IDecoder
{
public:
    Decoder3D(size_t order, const std::vector<float>& positions);

    ~Decoder3D() override = default;

    std::vector<float> decode(const std::vector<float>& encodedSample) override;

    size_t getNumberOfSpeakers() override;

private:

    hoa::DecoderRegular<hoa::Dimension::Hoa3d, float> hoaDecoder_;

    std::vector<float> output_;
};
