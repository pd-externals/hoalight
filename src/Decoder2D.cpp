#include "Decoder2D.h"
#include "Blauert.h"

Decoder2D::Decoder2D(size_t order, const std::vector<float>& positions)
: hoaDecoder_(order, positions.size())
{
    const auto numSpeaker = positions.size();
    output_.resize(numSpeaker);
    for(auto i = size_t(0); i < numSpeaker; ++i)
    {
        hoaDecoder_.setPlanewaveAzimuth(i, Blauert::toPhi(positions[i]));
    }
}

std::vector<float> Decoder2D::decode(const std::vector<float>& bFormat)
{
    hoaDecoder_.process(bFormat.data(), output_.data());
    return output_;
}

size_t Decoder2D::getNumberOfSpeakers() const
{
    return hoaDecoder_.getNumberOfPlanewaves();
}
