#pragma once

#include <IDecoder.h>

class DecoderMock : public IDecoder
{
public:
    MOCK_METHOD1(decode, std::vector<float>(const std::vector<float>& encodedSample));

    MOCK_CONST_METHOD0(getNumberOfSpeakers, size_t());
};
