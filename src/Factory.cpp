#include <memory>

#include "Factory.h"
#include "Encoder.h"
#include "Wider.h"
#include "Optim.h"
#include "Decoder.h"
#include "Pipeline.h"

EncoderPtr Factory::createEncoder2D(size_t order) const
{
    return std::make_unique<Encoder<hoa::Encoder<hoa::Hoa2d, float>::Basic>>(order);
}

EncoderPtr Factory::createEncoder3D(size_t order) const
{
    return std::make_unique<Encoder<hoa::Encoder<hoa::Hoa3d, float>::Basic>>(order);
}

WiderPtr Factory::createWider2D(size_t order) const
{
    return std::make_unique<Wider<hoa::Wider<hoa::Hoa2d, float>>>(order);
}

WiderPtr Factory::createWider3D(size_t order) const
{
    return std::make_unique<Wider<hoa::Wider<hoa::Hoa3d, float>>>(order);
}

ProcessorPtr Factory::createOptimMaxRe2D(size_t order) const
{
    return std::make_unique<Optim<hoa::Optim<hoa::Hoa2d, float>::MaxRe>>(order);
}

ProcessorPtr Factory::createOptimMaxRe3D(size_t order) const
{
    return std::make_unique<Optim<hoa::Optim<hoa::Hoa3d, float>::MaxRe>>(order);
}

ProcessorPtr Factory::createOptimInPhase2D(size_t order) const
{
    return std::make_unique<Optim<hoa::Optim<hoa::Hoa2d, float>::InPhase>>(order);
}

ProcessorPtr Factory::createOptimInPhase3D(size_t order) const
{
    return std::make_unique<Optim<hoa::Optim<hoa::Hoa3d, float>::InPhase>>(order);
}

DecoderPtr Factory::createDecoder2D(size_t order, const std::vector<float>& positions) const
{
    return std::make_unique<Decoder<hoa::Decoder<hoa::Hoa2d, float>::Regular>>(order, positions);
}

DecoderPtr Factory::createDecoder3D(size_t order, const std::vector<float>& positions) const
{
    return std::make_unique<Decoder<hoa::Decoder<hoa::Hoa3d, float>::Regular>>(order, positions);
}

PipelinePtr Factory::createPipeline(const PipelineProperty& pipelineProperty) const
{
    return std::make_unique<Pipeline>(pipelineProperty, *this);
}
