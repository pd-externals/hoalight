#include "HoaLight.h"

extern "C"
{
    HoaLight* createHoaLight();
    void destroyHoaLight(HoaLight* hoaLight);
    void setOrder(HoaLight* hoaLight, float order);
    float defineSpeakers(HoaLight* hoaLight, int argc, float *argv);
    float setAzimuth(HoaLight* hoaLight, float azimuth);
    float setElevation(HoaLight* hoaLight, float azimuth);
    float setRadius(HoaLight* hoaLight, float radius);
    float getAmplitude(HoaLight* hoaLight, float *amplitude);
}
