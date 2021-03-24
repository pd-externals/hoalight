#include "HoaLightWrapper.h"
#include "Factory.h"

HoaLight* createHoaLight()
{
    auto&& hoaLight = std::make_unique<HoaLight>(std::make_unique<Factory>());
    return hoaLight.release();
}

void destroyHoaLight(HoaLight* hoaLight)
{
    auto&& condemned = std::unique_ptr<HoaLight>(hoaLight);
}

void setOrder(HoaLight* hoaLight, float order)
{
    hoaLight->setOrder(order);
}

float defineSpeakers(HoaLight* hoaLight, int argc, float* argv)
{
    auto args = std::vector<float>(argv, argv+argc);
    return hoaLight->defineSpeakers(args) ? 1.f : 0.f;
}

float setAzimuth(HoaLight* hoaLight, float azimuth)
{
    return hoaLight->setAzimuth(azimuth) ? 1.f : 0.f;
}

float setElevation(HoaLight* hoaLight, float elevation)
{
    return hoaLight->setElevation(elevation) ? 1.f : 0.f;
}

float setRadius(HoaLight* hoaLight, float radius)
{
    return hoaLight->setRadius(radius) ? 1.f : 0.f;
}

float getAmplitude(HoaLight* hoaLight, float* outAmplitude)
{
    auto amps = hoaLight->getAmplitudes();
    if(amps.empty())
        return 0.f;

    std::memcpy(outAmplitude, amps.data(), sizeof(float) * amps.size());
    return 1.f;
}
