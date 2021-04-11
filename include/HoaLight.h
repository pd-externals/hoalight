#pragma once

#include <vector>
#include "IEncoder.h"
#include "IDecoder.h"
#include "IFactory.h"
#include "IPipeline.h"
#include "PipelineProperty.h"
#include "OptimType.h"

class HoaLight
{
public:
    HoaLight(FactoryPtr factory);

    void setOrder(int order);

    void setAzimuth(float azimuth);

    void setElevation(float elevation);

    void setRadius(float radius);

    void setOptim(OptimType optimType);

    void defineSpeakers(const std::vector<float>& defineSpeakers);

    std::vector<float> getAmplitudes() const;

    size_t getNumberOfSpeakers() const;

    bool isPrepared() const;

private:
    FactoryPtr factory_;
    PipelinePtr pipeline_;
    PipelineProperty pipelineProperty_;

    void reloadPipeline();
};
