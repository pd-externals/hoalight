#pragma once
#include <memory>
#include "IProcessor.h"

class IWider : public IProcessor
{
public:
    virtual ~IWider() = default;

    virtual void setWidening(float param) = 0;
};

using WiderPtr = std::unique_ptr<IWider>;
