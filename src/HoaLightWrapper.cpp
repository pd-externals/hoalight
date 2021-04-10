#include "HoaLightWrapper.h"
#include "Factory.h"
#include "HoaLight.h"
#include <string>

void* createHoaLight()
{
    auto&& hoaLight = std::make_unique<HoaLight>(std::make_unique<Factory>());
    return static_cast<void*>(hoaLight.release());
}

void destroyHoaLight(void* hoaLight)
{
    auto&& condemned = std::unique_ptr<HoaLight>(static_cast<HoaLight*>(hoaLight));
}

int setOrder(void* hoaLight, float order)
{
    auto* core = static_cast<HoaLight*>(hoaLight);
    core->setOrder(static_cast<int>(order));
}

int setOptim(void* hoaLight, char* optim)
{
    auto* core = static_cast<HoaLight*>(hoaLight);
    auto optimStr = std::string(optim);
    if(optimStr == "MaxRe")
    {
        core->setOptim(OptimType::MaxRe);
        return 1;
    }
    if(optimStr == "InPhase")
    {
        core->setOptim(OptimType::InPhase);
        return 1;
    }
    if(optimStr == "None")
    {
        core->setOptim(OptimType::None);
        return 1;
    }
    return 0;
}

int defineSpeakers(void* hoaLight, int argc, float* argv)
{
    auto* core = static_cast<HoaLight*>(hoaLight);
    auto args = std::vector<float>(argv, argv+argc);
    if(args.size() < 2)
        return 0;
    if(!(args[0] == 2.f || args[0] == 3.f))
        return 0;
    core->defineSpeakers(args);
    return 1;
}

int setAzimuth(void* hoaLight, float azimuth)
{
    auto* core = static_cast<HoaLight*>(hoaLight);
    if(!core->isPrepared())
        return 0;
    core->setAzimuth(azimuth);
    return 1;
}

int setElevation(void* hoaLight, float elevation)
{
    auto* core = static_cast<HoaLight*>(hoaLight);
    if(!core->isPrepared())
        return 0;
    core->setElevation(elevation);
    return 1;
}

int setRadius(void* hoaLight, float radius)
{
    auto* core = static_cast<HoaLight*>(hoaLight);
    if(!core->isPrepared())
        return 0;
    core->setRadius(radius);
    return 1;
}

int getAmplitudes(void* hoaLight, float* outAmplitude)
{
    auto* core = static_cast<HoaLight*>(hoaLight);
    if(!core->isPrepared())
        return 0;
    auto amps = core->getAmplitudes();
    std::memcpy(outAmplitude, amps.data(), sizeof(float) * amps.size());
    return 1;
}

int getNumberOfSpeakers(void* hoaLight)
{
    auto* core = static_cast<HoaLight*>(hoaLight);
    if(!core->isPrepared())
        return 0;
    auto numSpeakers = static_cast<HoaLight*>(hoaLight)->getNumberOfSpeakers();
    return static_cast<int>(numSpeakers);
}