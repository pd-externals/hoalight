#pragma once

#include <Hoa.hpp>
#include "Blauert.h"
#include "Dimension.h"
#include "IEncoder.h"
#include "IFactory.h"

template<typename T>
struct EncoderDispatcher{};

template<>
struct EncoderDispatcher<hoa::Encoder<hoa::Hoa2d, float>::Basic>
{
    static void setElevation(hoa::Encoder<hoa::Hoa2d, float>::Basic& encoder, float elevation)
    {
        // do nothing
    }
};

template<>
struct EncoderDispatcher<hoa::Encoder<hoa::Hoa3d, float>::Basic>
{
    static void setElevation(hoa::Encoder<hoa::Hoa3d, float>::Basic& encoder, float elevation)
    {
        const auto theta = Blauert::toTheta(elevation);
        encoder.setElevation(theta);
    }
};

template <typename T>
class Encoder : public IEncoder
{
public:
    Encoder(size_t order)
    :encoder_(order)
    {}

    ~Encoder() override = default;

    void setAzimuth(float azimuth) override
    {
        const auto phi = Blauert::toPhi(azimuth);
        encoder_.setAzimuth(phi);
    }

    void setElevation(float elevation) override
    {
        EncoderDispatcher<T>::setElevation(encoder_, elevation);
    }

    std::vector<float> process() override
    {
        const static auto input = 1.f;
        auto&& output = std::vector<float>(encoder_.getNumberOfHarmonics());
        encoder_.process(&input, output.data());
        return output;
    }

private:
    T encoder_;
};

