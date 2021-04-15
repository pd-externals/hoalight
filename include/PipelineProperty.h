#pragma once

#include "Dimension.h"
#include "OptimType.h"

struct PipelineProperty
{
    Dimension dimension = Dimension::Unknown;
    std::vector<float> speakerPositions;
    size_t order = 1;
    OptimType optimType = OptimType::None;
};
