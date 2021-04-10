#pragma once
#include "IFactory.h"

class Factory : public IFactory
{
public:
    ~Factory() = default;

    EncoderPtr createEncoder2D(size_t order) const override;

    EncoderPtr createEncoder3D(size_t order) const override;

    WiderPtr createWider2D(size_t order) const override;

    WiderPtr createWider3D(size_t order) const override;

    OptimPtr createOptimMaxRe2D(size_t order) const override;

    OptimPtr createOptimMaxRe3D(size_t order) const override;

    OptimPtr createOptimInPhase2D(size_t order) const override;

    OptimPtr createOptimInPhase3D(size_t order) const override;

    DecoderPtr createDecoder2D(size_t order, const std::vector<float>& positions) const override;

    DecoderPtr createDecoder3D(size_t order, const std::vector<float>& positions) const override;

    PipelinePtr createPipeline(const PipelineProperty& pipelineProperty) const override;
};