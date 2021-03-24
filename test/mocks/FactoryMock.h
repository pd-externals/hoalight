#pragma once
#include <IFactory.h>

class FactoryMock : public IFactory {
public:
    MOCK_CONST_METHOD2(createEncoder, EncoderPtr(Dimension dimension, size_t order));

    MOCK_CONST_METHOD1(createEncoder2D, EncoderPtr(size_t order));

    MOCK_CONST_METHOD1(createEncoder3D, EncoderPtr(size_t order));

    MOCK_CONST_METHOD3(createDecoder,
                       DecoderPtr(Dimension dimension, size_t order, const std::vector<float>& positions));
    MOCK_CONST_METHOD2(createDecoder2D,
                       DecoderPtr(size_t order, const std::vector<float>& positions));
    MOCK_CONST_METHOD2(createDecoder3D,
                       DecoderPtr(size_t order, const std::vector<float>& positions));
};
