#include <algorithm>
#include "Blauert.h"

namespace Blauert
{
    constexpr auto pi = static_cast<float>(M_PI);

    float toPhi(float azimuth)
    {
        auto folded = azimuth > 90.f ? azimuth - 360.f : azimuth;
        return (1.0f - (folded + 270.f) / 360.f) * pi * 2.f;
    }

    float toTheta(float elevation)
    {
        return elevation/180.f * pi;
    }
}
