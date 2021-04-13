#include <algorithm>
#include "Blauert.h"

namespace Blauert
{
    constexpr auto pi = static_cast<float>(M_PI);

    float toPhi(float azimuth)
    {
        return azimuth / 360.f * pi * 2.f;
    }

    float toTheta(float elevation)
    {
        return elevation / 180.f * pi;
    }
}
