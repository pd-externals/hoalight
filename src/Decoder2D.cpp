#include "Decoder2D.h"

Decoder2D::Decoder2D(size_t order, const std::vector<float>& positions)
: hoaDecoder_(order, positions.size())
{
    const auto numSpeaker = positions.size();
    output_.resize(numSpeaker);
    for(auto i = size_t(0); i < numSpeaker; ++i)
    {
        hoaDecoder_.setPlanewaveAzimuth(i, positions[i]);
    }
    hoaDecoder_.prepare();
}

std::vector<float> Decoder2D::decode(const std::vector<float>& encodedSample)
{
    hoaDecoder_.process(encodedSample.data(), output_.data());
    return output_;
}

size_t Decoder2D::getNumberOfSpeakers()
{
    return hoaDecoder_.getNumberOfPlanewaves();
}
