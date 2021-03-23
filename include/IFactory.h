#pragma once

#include "IEncoder.h"
#include "Dimension.h"

class IFactory
{
public:
    virtual ~IFactory() = default;

    virtual EncoderPtr createEncoder(Dimension dimension, size_t order) const = 0;

    virtual EncoderPtr createEncoder2D(size_t order) const = 0;

    virtual EncoderPtr createEncoder3D(size_t order) const = 0;
};


