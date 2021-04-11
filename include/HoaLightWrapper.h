
#ifdef __cplusplus
extern "C"{
#else
#include <stdbool.h>
#endif

    void* createHoaLight();
    void destroyHoaLight(void* hoaLight);
    void setOrder(void* hoaLight, float order);
    bool defineSpeakers(void* hoaLight, int argc, float *argv);
    bool setAzimuth(void* hoaLight, float azimuth);
    bool setElevation(void* hoaLight, float azimuth);
    bool setRadius(void* hoaLight, float radius);
    bool setOptim(void* hoaLight, const char* optim);
    bool getAmplitudes(void* hoaLight, float *amplitude);
    int getNumberOfSpeakers(void* hoaLight);

#ifdef __cplusplus
}
#endif

