#pragma once

#include <vector>
#include <Hoa.hpp>
#include "IWider.h"

template <typename T>
class Wider : public IWider
{
public:
    Wider(size_t order)
    :wider_(order)
    {}

    ~Wider() override = default;

    void setWidening(float radius) override
    {
        wider_.setWidening(radius);
    }

    std::vector<float> process(const std::vector<float>& input) override
    {
        std::vector<float> out;
        out.resize(input.size());
        wider_.process(input.data(), out.data());
        return out;
    }

private:
    T wider_;
};
