#pragma once
#include "Dimension.h"
#include "IDecoder.h"
#include "IFactory.h"

class Decoder : public IDecoder
{
public:
    Decoder(Dimension dimension, size_t order, const std::vector<float>& positions, const IFactory& factory);

    ~Decoder() override = default;

    std::vector<float> decode(const std::vector<float>& encodedSample) override;

private:
    DecoderPtr hoaDecoder_;

};
