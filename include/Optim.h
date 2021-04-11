#pragma once

#include "IProcessor.h"
#include <Hoa.hpp>

template <typename T>
class Optim : public IProcessor
{
public:
    Optim(size_t order)
    : optim_(order)
    {
    }

    ~Optim() override = default;

    std::vector<float> process(const std::vector<float>& input) override
    {
        std::vector<float> out;
        out.resize(input.size());
        optim_.process(input.data(), out.data());
        return out;
    }

private:
    T optim_;
};