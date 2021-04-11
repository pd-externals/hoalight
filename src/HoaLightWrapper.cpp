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
    std::unique_ptr<HoaLight>(static_cast<HoaLight*>(hoaLight));
}

void setOrder(void* hoaLight, float order)
{
    auto* core = static_cast<HoaLight*>(hoaLight);
    core->setOrder(static_cast<int>(order));
}

bool setOptim(void* hoaLight, const char* optim)
{
    auto* core = static_cast<HoaLight*>(hoaLight);
    auto optimStr = std::string(optim);
    if(optimStr == "MaxRe")
    {
        core->setOptim(OptimType::MaxRe);
        return true;
    }
    if(optimStr == "InPhase")
    {
        core->setOptim(OptimType::InPhase);
        return true;
    }
    if(optimStr == "None")
    {
        core->setOptim(OptimType::None);
        return true;
    }
    return false;
}

bool defineSpeakers(void* hoaLight, int argc, float* argv)
{
    auto* core = static_cast<HoaLight*>(hoaLight);
    auto args = std::vector<float>(argv, argv+argc);
    if(args.size() < 2)
        return false;
    if(!(args[0] == 2.f || args[0] == 3.f))
        return false;
    core->defineSpeakers(args);
    return true;
}

bool setAzimuth(void* hoaLight, float azimuth)
{
    auto* core = static_cast<HoaLight*>(hoaLight);
    if(!core->isPrepared())
        return false;
    core->setAzimuth(azimuth);
    return true;
}

bool setElevation(void* hoaLight, float elevation)
{
    auto* core = static_cast<HoaLight*>(hoaLight);
    if(!core->isPrepared())
        return false;
    core->setElevation(elevation);
    return true;
}

bool setRadius(void* hoaLight, float radius)
{
    auto* core = static_cast<HoaLight*>(hoaLight);
    if(!core->isPrepared())
        return false;
    core->setRadius(radius);
    return true;
}

bool getAmplitudes(void* hoaLight, float* outAmplitude)
{
    auto* core = static_cast<HoaLight*>(hoaLight);
    if(!core->isPrepared())
        return false;
    auto amps = core->getAmplitudes();
    std::memcpy(outAmplitude, amps.data(), sizeof(float) * amps.size());
    return true;
}

int getNumberOfSpeakers(void* hoaLight)
{
    auto* core = static_cast<HoaLight*>(hoaLight);
    if(!core->isPrepared())
        return 0;
    auto numSpeakers = static_cast<HoaLight*>(hoaLight)->getNumberOfSpeakers();
    return static_cast<int>(numSpeakers);
}