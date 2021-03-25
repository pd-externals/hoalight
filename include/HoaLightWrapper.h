
#ifdef __cplusplus
extern "C"{
#endif

    void* createHoaLight();
    void destroyHoaLight(void* hoaLight);
    int setOrder(void* hoaLight, float order);
    int defineSpeakers(void* hoaLight, int argc, float *argv);
    int setAzimuth(void* hoaLight, float azimuth);
    int setElevation(void* hoaLight, float azimuth);
    int setRadius(void* hoaLight, float radius);
    int getAmplitudes(void* hoaLight, float *amplitude);
    int getNumberOfSpeakers(void* hoaLight);

#ifdef __cplusplus
}
#endif

