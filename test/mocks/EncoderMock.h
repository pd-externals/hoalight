#pragma once
#include <gmock/gmock.h>
#include <IEncoder.h>

class EncoderMock : public IEncoder {

public:
    MOCK_METHOD1(setRadius, void(float radius));

    MOCK_METHOD1(setAzimuth, void(float azimuth));

    MOCK_METHOD1(setElevation, void(float elevation));

    MOCK_METHOD0(process, std::vector<float>());
};
