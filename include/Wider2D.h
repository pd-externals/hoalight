#pragma once

#include <vector>
#include <Hoa.hpp>
#include "IWider.h"

class Wider2D : public IWider
{
public:
    Wider2D(size_t order);

    ~Wider2D() override = default;

    void setWidening(float radius) override;

    std::vector<float> process(const std::vector<float>& bFormat) override;

private:
    hoa::Wider<hoa::Dimension::Hoa2d, float> wider_;
};
