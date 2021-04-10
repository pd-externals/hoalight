#pragma once
#include <vector>

#include "PipelineProperty.h"
#include "IPipeline.h"
#include "IEncoder.h"
#include "IOptim.h"
#include "IWider.h"
#include "IDecoder.h"
#include "IFactory.h"

class Pipeline : public IPipeline
{
public:
    Pipeline(const PipelineProperty& pipelineProperty, const IFactory& factory);

    std::vector<float> process() override;

    void setAzimuth(float azimuth) override;

    void setElevation(float elevation) override;

    void setRadius(float radius) override;

    size_t getNumberOfSpeakers() const override;

private:
    EncoderPtr encoder_;
    WiderPtr wider_;
    OptimPtr optim_;
    DecoderPtr decoder_;
};
