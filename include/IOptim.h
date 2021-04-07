#pragma once
#include <memory>

class IOptim
{
public:

    virtual ~IOptim() = default;

    virtual void process(float* in, float* out);
};

using OptimPtr = std::unique_ptr<IOptim>;
