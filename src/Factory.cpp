#include "Factory.h"
#include "Encoder.h"
#include "Encoder2D.h"
#include "Encoder3D.h"

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
