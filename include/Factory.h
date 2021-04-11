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

    ProcessorPtr createOptimMaxRe2D(size_t order) const override;

    ProcessorPtr createOptimMaxRe3D(size_t order) const override;

    ProcessorPtr createOptimInPhase2D(size_t order) const override;

    ProcessorPtr createOptimInPhase3D(size_t order) const override;

    DecoderPtr createDecoder2D(size_t order, const std::vector<float>& positions) const override;

    DecoderPtr createDecoder3D(size_t order, const std::vector<float>& positions) const override;

    PipelinePtr createPipeline(const PipelineProperty& pipelineProperty) const override;
};