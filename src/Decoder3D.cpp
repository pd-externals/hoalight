#include "Decoder3D.h"

Decoder3D::Decoder3D(size_t order, const std::vector<float>& positions)
: hoaDecoder_(order, positions.size()/2)
{
    const auto numSpeaker = positions.size()/2;
    output_.resize(numSpeaker);

    for(auto i = size_t(0); i < numSpeaker; ++i)
    {
        hoaDecoder_.setPlanewaveAzimuth(i, positions[i*2]);
        hoaDecoder_.setPlanewaveElevation(i, positions[i*2+1]);
    }
    hoaDecoder_.prepare();
}

std::vector<float> Decoder3D::decode(const std::vector<float>& encodedSample)
{
    hoaDecoder_.process(encodedSample.data(), output_.data());
    return output_;
}
