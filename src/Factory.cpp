#include "Factory.h"
#include "Encoder.h"
#include "Encoder2D.h"
#include "Encoder3D.h"
#include "Wider2D.h"
#include "Wider3D.h"
#include "OptimInPhase2D.h"
#include "OptimInPhase3D.h"
#include "OptimMaxRe2D.h"
#include "OptimMaxRe3D.h"
#include "Decoder.h"
#include "Decoder2D.h"
#include "Decoder3D.h"

EncoderPtr Factory::createEncoder(Dimension dimension, size_t order) const
{
    return std::make_unique<Encoder>(dimension, order, *this);
}

EncoderPtr Factory::createEncoder2D(size_t order) const
{
    return std::make_unique<Encoder2D>(order);
}

EncoderPtr Factory::createEncoder3D(size_t order) const
{
    return std::make_unique<Encoder3D>(order);
}

WiderPtr Factory::createWider2D(size_t order) const
{
    return std::make_unique<Wider2D>(order);
}

WiderPtr Factory::createWider3D(size_t order) const
{
    return std::make_unique<Wider3D>(order);
}

OptimPtr Factory::createOptimMaxRe2D(size_t order) const
{
    return std::make_unique<OptimMaxRe2D>(order);
}

OptimPtr Factory::createOptimMaxRe3D(size_t order) const
{
    return std::make_unique<OptimMaxRe3D>(order);
}

OptimPtr Factory::createOptimInPhase2D(size_t order) const
{
    return std::make_unique<OptimInPhase2D>(order);
}

OptimPtr Factory::createOptimInPhase3D(size_t order) const
{
    return std::make_unique<OptimInPhase3D>(order);
}

DecoderPtr Factory::createDecoder(Dimension dimension, size_t order, const std::vector<float>& positions) const
{
    return std::make_unique<Decoder>(dimension, order, positions, *this);
}

DecoderPtr Factory::createDecoder2D(size_t order, const std::vector<float>& positions) const
{
    return std::make_unique<Decoder2D>(order, positions);
}

DecoderPtr Factory::createDecoder3D(size_t order, const std::vector<float>& positions) const
{
    return std::make_unique<Decoder3D>(order, positions);
}
