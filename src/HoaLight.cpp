#include "HoaLight.h"

HoaLight::HoaLight(FactoryPtr factory)
: factory_(std::move(factory))
{}

void HoaLight::setOrder(int order)
{
    pipelineProperty_.order = std::clamp(order, 1, 16);
    if(pipeline_!= nullptr)
        reloadPipeline();
}

void HoaLight::defineSpeakers(const std::vector<float>& defineSpeakers)
{
    if(defineSpeakers[0] == 2.f)
        pipelineProperty_.dimension = Dimension::Two;
    else if(defineSpeakers[0] == 3.f)
        pipelineProperty_.dimension = Dimension::Three;

    pipelineProperty_.speakerPositions = std::vector(defineSpeakers.begin() + 1, defineSpeakers.end());
    reloadPipeline();
}

void HoaLight::setAzimuth(float azimuth)
{
    pipeline_->setAzimuth(azimuth);
}

void HoaLight::setElevation(float elevation)
{
    pipeline_->setElevation(elevation);
}

void HoaLight::setRadius(float radius)
{
    pipeline_->setRadius(radius);
}

void HoaLight::setOptim(OptimType optimType)
{
    pipelineProperty_.optimType = optimType;
    if(pipeline_!= nullptr)
        reloadPipeline();
}

std::vector<float> HoaLight::getAmplitudes() const
{
    return pipeline_->process();
}

size_t HoaLight::getNumberOfSpeakers() const
{
    return pipeline_->getNumberOfSpeakers();
}

bool HoaLight::isPrepared() const
{
    return pipeline_ != nullptr;
}

void HoaLight::reloadPipeline()
{
    pipeline_ = factory_->createPipeline(pipelineProperty_);
}