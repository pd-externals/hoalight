#pragma once
#include "IFactory.h"

class Factory : public IFactory
{
public:
    ~Factory() = default;

    EncoderPtr createEncoder(Dimension dimension, size_t order) const override;

    EncoderPtr createEncoder2D(size_t order) const override;

    EncoderPtr createEncoder3D(size_t order) const override;
};