#include "Decoder.h"

Decoder::Decoder(Dimension dimension, size_t order, const std::vector<float>& positions, const IFactory& factory)
: hoaDecoder_(dimension == Dimension::TWO ?
factory.createDecoder2D(order, positions) : factory.createDecoder3D(order, positions))
{

}

std::vector<float> Decoder::decode(const std::vector<float>& encodedSample)
{
    return hoaDecoder_->decode(encodedSample);
}
