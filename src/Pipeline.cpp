#include "Pipeline.h"
#include <stdexcept>

namespace
{
    ProcessorPtr createOptim(const PipelineProperty& pp, const IFactory& factory)
    {
        if(pp.optimType == OptimType::None)
            return nullptr;
        if(pp.optimType == OptimType::MaxRe)
            return pp.dimension == Dimension::Two ? factory.createOptimMaxRe2D(pp.order) : factory.createOptimMaxRe3D(pp.order);
        return pp.dimension == Dimension::Two ? factory.createOptimInPhase2D(pp.order) : factory.createOptimInPhase3D(pp.order);
    }
}

Pipeline::Pipeline(const PipelineProperty& pp, const IFactory& factory)
: encoder_(pp.dimension == Dimension::Two ? factory.createEncoder2D(pp.order) : factory.createEncoder3D(pp.order))
, wider_(pp.dimension == Dimension::Two ? factory.createWider2D(pp.order) : factory.createWider3D(pp.order))
, optim_(createOptim(pp, factory))
, decoder_(pp.dimension == Dimension::Two ? factory.createDecoder2D(pp.order, pp.speakerPositions) : factory.createDecoder3D(pp.order, pp.speakerPositions))
{
    if(pp.dimension == Dimension::Unknown || pp.speakerPositions.size() < 1)
        throw std::invalid_argument("invalid pipeline property");
}

std::vector<float> Pipeline::process()
{
    auto bFormat = encoder_->process();
    bFormat = wider_->process(bFormat);
    if(optim_)
        bFormat = optim_->process(bFormat);
    return decoder_->process(bFormat);
}

void Pipeline::setAzimuth(float azimuth)
{
    encoder_->setAzimuth(azimuth);
}

void Pipeline::setElevation(float elevation)
{
    encoder_->setElevation(elevation);
}

void Pipeline::setRadius(float radius)
{
    wider_->setWidening(1.f - (std::clamp(radius, 0.f, 100.f) / 100.f));
}

size_t Pipeline::getNumberOfSpeakers() const
{
    return decoder_->getNumberOfSpeakers();
}

