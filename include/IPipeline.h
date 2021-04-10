#pragma once

#include <memory>

class IPipeline
{

public:
    virtual ~IPipeline() = default;

    virtual void setAzimuth(float azimuth) = 0;

    virtual void setElevation(float elevation) = 0;

    virtual void setRadius(float radius) = 0;

    virtual size_t getNumberOfSpeakers() const = 0;

    virtual std::vector<float> process() = 0;
};

using PipelinePtr = std::unique_ptr<IPipeline>;

