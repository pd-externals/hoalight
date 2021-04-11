#pragma once

#include <IDecoder.h>

class DecoderMock : public IDecoder
{
public:
    ~DecoderMock() = default;

    MOCK_METHOD1(process, std::vector<float>(const std::vector<float>& encodedSample));

    MOCK_CONST_METHOD0(getNumberOfSpeakers, size_t());
};
