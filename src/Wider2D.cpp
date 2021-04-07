#include "Wider2D.h"

Wider2D::Wider2D(size_t order)
:wider_(order)
{
}

void Wider2D::setWidening(float radius)
{
    wider_.setWidening(radius);
}

std::vector<float> Wider2D::process(const std::vector<float>& bFormat)
{
    return IWider::process(bFormat);
}

