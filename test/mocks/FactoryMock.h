#pragma once
#include <IFactory.h>

class FactoryMock : public IFactory {
public:
    ~FactoryMock() = default;

    MOCK_CONST_METHOD1(createEncoder2D, EncoderPtr(size_t order));

    MOCK_CONST_METHOD1(createEncoder3D, EncoderPtr(size_t order));

    MOCK_CONST_METHOD1(createWider2D, WiderPtr(size_t order));

    MOCK_CONST_METHOD1(createWider3D, WiderPtr(size_t order));

    MOCK_CONST_METHOD1(createOptimMaxRe2D, ProcessorPtr(size_t order));

    MOCK_CONST_METHOD1(createOptimMaxRe3D, ProcessorPtr(size_t order));

    MOCK_CONST_METHOD1(createOptimInPhase2D, ProcessorPtr(size_t order));

    MOCK_CONST_METHOD1(createOptimInPhase3D, ProcessorPtr(size_t order));

    MOCK_CONST_METHOD2(createDecoder2D, DecoderPtr(size_t order, const std::vector<float>& positions));

    MOCK_CONST_METHOD2(createDecoder3D, DecoderPtr(size_t order, const std::vector<float>& positions));

    MOCK_CONST_METHOD1(createPipeline, PipelinePtr(const PipelineProperty& pipelineProperty));
};

