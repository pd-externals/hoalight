#pragma once
#include <IPipeline.h>

class PipelineMock : public IPipeline {

public:
    MOCK_METHOD1(setAzimuth, void(float azimuth));

    MOCK_METHOD1(setElevation, void(float elevation));

    MOCK_METHOD1(setRadius, void(float radius));

    MOCK_CONST_METHOD0(getNumberOfSpeakers, size_t());

    MOCK_METHOD0(process, std::vector<float>());
};
