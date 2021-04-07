#pragma once

#include <vector>
#include <Hoa.hpp>
#include "IWider.h"

class Wider3D : public IWider
{
public:
    Wider3D(size_t order);

    ~Wider3D() override = default;

    void setWidening(float radius) override;

    std::vector<float> process(const std::vector<float>& bFormat) override;

private:
    hoa::Wider<hoa::Dimension::Hoa3d, float> wider_;
};
