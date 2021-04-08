#pragma once
#include <memory>

class IOptim
{
public:

    virtual ~IOptim() = default;

    virtual std::vector<float> process(const std::vector<float>& bFormat) = 0;
};

using OptimPtr = std::unique_ptr<IOptim>;
