#pragma once

#include "Dimension.h"
#include "OptimType.h"

struct PipelineProperty
{
    Dimension dimension = Dimension::Two;
    size_t order = 1;
    OptimType optimType = OptimType::None;
    std::vector<float> speakerPositions;
};

