#pragma once

#include "IEncoder.h"
#include "Dimension.h"

class IFactory
{
public:
    virtual ~IFactory() = default;

    virtual EncoderPtr CreateEncoder(Dimension dimension, size_t order) const = 0;

    virtual EncoderPtr CreateEncoder2D(size_t order) const = 0;

    virtual EncoderPtr CreateEncoder3D(size_t order) const = 0;
};


