#pragma once
#include "IFactory.h"

class Factory : public IFactory
{
public:
    ~Factory() = default;

    EncoderPtr CreateEncoder(Dimension dimension, size_t order) const override;

    EncoderPtr CreateEncoder2D(size_t order) const override;

    EncoderPtr CreateEncoder3D(size_t order) const override;
};