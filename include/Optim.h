#pragma once

#include "IOptim.h"
#include <Hoa.hpp>

template <typename T>
class Optim : public IOptim
{
public:
    Optim(size_t order)
    : optim_(order)
    {
    }

    ~Optim() override = default;

    std::vector<float> process(const std::vector<float>& bFormat) override
    {
        std::vector<float> out;
        out.resize(bFormat.size());
        optim_.process(&bFormat[0], &out[0]);
        return out;
    }

private:
    T optim_;
};