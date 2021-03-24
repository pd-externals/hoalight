#pragma once

#include "IEncoder.h"
#include "Dimension.h"
#include "IDecoder.h"

class IFactory
{
public:
    virtual ~IFactory() = default;

    virtual EncoderPtr createEncoder(Dimension dimension, size_t order) const = 0;

    virtual EncoderPtr createEncoder2D(size_t order) const = 0;

    virtual EncoderPtr createEncoder3D(size_t order) const = 0;

    virtual DecoderPtr createDecoder(Dimension dimension, size_t order, const std::vector<float>& positions) const = 0;

    virtual DecoderPtr createDecoder2D(size_t order, const std::vector<float>& positions) const = 0;

    virtual DecoderPtr createDecoder3D(size_t order, const std::vector<float>& positions) const = 0;
};
