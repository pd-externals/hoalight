#include "Factory.h"
#include "Encoder.h"
#include "Encoder2D.h"
#include "Encoder3D.h"
#include "Decoder.h"
#include "Decoder2D.h"
#include "Decoder3D.h"

EncoderPtr Factory::createEncoder(Dimension dimension, size_t order) const
{
    return std::make_unique<Encoder>(dimension, order, *this);
}

EncoderPtr Factory::createEncoder2D(size_t order) const
{
    return std::make_unique<Encoder2D>(order);
}

EncoderPtr Factory::createEncoder3D(size_t order) const
{
    return std::make_unique<Encoder3D>(order);
}

DecoderPtr Factory::createDecoder(Dimension dimension, size_t order, const std::vector<float>& positions) const
{
    return std::make_unique<Decoder>(dimension, order, positions, *this);
}

DecoderPtr Factory::createDecoder2D(size_t order, const std::vector<float>& positions) const
{
    return std::make_unique<Decoder2D>(order, positions);
}

DecoderPtr Factory::createDecoder3D(size_t order, const std::vector<float>& positions) const
{
    return std::make_unique<Decoder3D>(order, positions);
}
