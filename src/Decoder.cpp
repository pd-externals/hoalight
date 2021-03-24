#include "Decoder.h"

namespace
{
    DecoderPtr createDecoder(Dimension dimension, size_t order, const std::vector<float>& positions, const IFactory& factory)
    {
        return dimension == Dimension::Two ?
            factory.createDecoder2D(order, positions) :
            factory.createDecoder3D(order, positions);
    }
}


Decoder::Decoder(Dimension dimension, size_t order, const std::vector<float>& positions, const IFactory& factory)
: hoaDecoder_(createDecoder(dimension, order, positions, factory))
{
}

std::vector<float> Decoder::decode(const std::vector<float>& encodedSample)
{
    return hoaDecoder_->decode(encodedSample);
}
