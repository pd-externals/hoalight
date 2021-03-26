#include <algorithm>
#include "Blauert.h"

namespace Blauert
{
    constexpr auto pi = static_cast<float>(M_PI);

    float toPhi(float azimuth)
    {
        auto clamped = std::clamp(azimuth, -180.f, 180.f);
        auto folded = clamped > 90.f ? clamped - 360.f : clamped;
        return (1.0f - (folded + 270.f) / 360.f) * pi * 2.f;
    }

    float toTheta(float elevation)
    {
        auto clamped = std::clamp(elevation, -90.f, 90.f);
        return clamped/180.f * pi;
    }
}
