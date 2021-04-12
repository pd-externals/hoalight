#pragma once

#include <algorithm>
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

    void setWidening(float param) override
    {
        wider_.setWidening(param);
    }

    std::vector<float> process(const std::vector<float>& input) override
    {
        auto&& out = std::vector<float>(input.size());
        wider_.process(input.data(), out.data());
        return out;
    }

private:
    T wider_;
};
