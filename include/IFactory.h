#pragma once

#include "Dimension.h"
#include "IEncoder.h"
#include "IWider.h"
#include "IOptim.h"
#include "IDecoder.h"
#include "IPipeline.h"
#include "PipelineProperty.h"

class IFactory
{
public:
    virtual ~IFactory() = default;

    virtual EncoderPtr createEncoder2D(size_t order) const = 0;

    virtual EncoderPtr createEncoder3D(size_t order) const = 0;

    virtual WiderPtr createWider2D(size_t order) const = 0;

    virtual WiderPtr createWider3D(size_t order) const = 0;

    virtual OptimPtr createOptimMaxRe2D(size_t order) const = 0;

    virtual OptimPtr createOptimMaxRe3D(size_t order) const = 0;

    virtual OptimPtr createOptimInPhase2D(size_t order) const = 0;

    virtual OptimPtr createOptimInPhase3D(size_t order) const = 0;

    virtual DecoderPtr createDecoder2D(size_t order, const std::vector<float>& positions) const = 0;

    virtual DecoderPtr createDecoder3D(size_t order, const std::vector<float>& positions) const = 0;

    virtual PipelinePtr createPipeline(const PipelineProperty& pipelineProperty) const = 0;
};

using FactoryPtr = std::unique_ptr<IFactory>;
