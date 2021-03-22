#include "Factory.h"
#include "Encoder.h"
#include "Encoder2D.h"
#include "Encoder3D.h"

EncoderPtr Factory::CreateEncoder(Dimension dimension, size_t order) const
{
    return std::make_unique<Encoder>(dimension, order, *this);
}

EncoderPtr Factory::CreateEncoder2D(size_t order) const
{
    return std::make_unique<Encoder2D>(order);
}

EncoderPtr Factory::CreateEncoder3D(size_t order) const
{
    return std::make_unique<Encoder3D>(order);
}
