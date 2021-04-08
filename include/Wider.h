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

    std::vector<float> process(const std::vector<float>& bFormat) override
    {
        return IWider::process(bFormat);
    }

private:
    T wider_;
};
