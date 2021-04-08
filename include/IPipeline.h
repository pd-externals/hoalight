#pragma once

#include <memory>

class IPipeline
{

public:
    virtual ~IPipeline() = default;

    virtual std::vector<float> process() = 0;
};

using PipelinePtr = std::unique_ptr<IPipeline>;

