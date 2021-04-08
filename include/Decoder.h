#pragma once
#include <Hoa.hpp>

#include "Dimension.h"
#include "IDecoder.h"
#include "IFactory.h"
#include "Blauert.h"

template<typename T>
struct DecoderDispatcher
{
};

template<>
struct DecoderDispatcher<hoa::Decoder<hoa::Hoa2d, float>::Regular>
{
    static void setPositions(hoa::Decoder<hoa::Hoa2d, float>& decoder, const std::vector<float>& positions)
    {
        for (auto i = size_t(0); i < positions.size(); ++i)
            decoder.setPlanewaveAzimuth(i, Blauert::toPhi(positions[i]));
    }
};

template<>
struct DecoderDispatcher<hoa::Decoder<hoa::Hoa3d, float>::Regular>
{
    static void setPositions(hoa::Decoder<hoa::Hoa3d, float>& decoder, const std::vector<float>& positions)
    {
        for (auto i = size_t(0); i < positions.size(); ++i)
        {
            decoder.setPlanewaveAzimuth(i, Blauert::toPhi(positions[i * 2]));
            decoder.setPlanewaveElevation(i, Blauert::toTheta(positions[i * 2 + 1]));
        }
    }
};

template <typename T>
class Decoder : public IDecoder
{
public:
    Decoder(size_t order, const std::vector<float>& positions)
    :decoder_(order, positions.size())
    {
        const auto numSpeaker = positions.size();
        output_.resize(numSpeaker);
        DecoderDispatcher<T>::setPositions(decoder_, positions);
    }

    ~Decoder() override = default;

    std::vector<float> decode(const std::vector<float>& encodedSample) override
    {
        decoder_.process(encodedSample.data(), output_.data());
        return output_;
    }

    size_t getNumberOfSpeakers() const override
    {
        decoder_.getNumberOfPlanewaves();
    }

private:
    T decoder_;
    std::vector<float> output_;
};
