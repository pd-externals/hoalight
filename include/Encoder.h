#pragma once

#include <Hoa.hpp>
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
    static void setElevation(hoa::Encoder<hoa::Hoa3d, float>::Basic& encoder, float theta)
    {
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

    void setAzimuth(float phi) override
    {
        encoder_.setAzimuth(phi);
    }

    void setElevation(float theta) override
    {
        EncoderDispatcher<T>::setElevation(encoder_, theta);
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

