#include "HoaLightWrapper.h"
#include "Factory.h"
#include "HoaLight.h"

void* createHoaLight()
{
    auto&& hoaLight = std::make_unique<HoaLight>(std::make_unique<Factory>());
    return static_cast<void*>(hoaLight.release());
}

void destroyHoaLight(void* hoaLight)
{
    auto&& condemned = std::unique_ptr<HoaLight>(static_cast<HoaLight*>(hoaLight));
}

void setOrder(void* hoaLight, float order)
{
    static_cast<HoaLight*>(hoaLight)->setOrder(order);
}

int defineSpeakers(void* hoaLight, int argc, float* argv)
{
    auto args = std::vector<float>(argv, argv+argc);
    return static_cast<HoaLight*>(hoaLight)->defineSpeakers(args) ? 1 : 0;
}

int setAzimuth(void* hoaLight, float azimuth)
{
    return static_cast<HoaLight*>(hoaLight)->setAzimuth(azimuth) ? 1: 0;
}

int setElevation(void* hoaLight, float elevation)
{
    return static_cast<HoaLight*>(hoaLight)->setElevation(elevation) ? 1 : 0;
}

int setRadius(void* hoaLight, float radius)
{
    return static_cast<HoaLight*>(hoaLight)->setRadius(radius) ? 1 : 0;
}

int getAmplitudes(void* hoaLight, float* outAmplitude)
{
    auto amps = static_cast<HoaLight*>(hoaLight)->getAmplitudes();
    if(amps.empty())
        return 0;

    std::memcpy(outAmplitude, amps.data(), sizeof(float) * amps.size());
    return 1;
}

int getNumberOfSpeakers(void* hoaLight)
{
    auto numSpeakers = static_cast<HoaLight*>(hoaLight)->getNumberOfSpeakers();
    return static_cast<int>(numSpeakers);
}