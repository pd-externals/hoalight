#pragma once
#include <memory>

class IWider
{
public:
    virtual ~IWider() = default;

    virtual void setWidening(float radius) = 0;

    virtual std::vector<float> process(const std::vector<float>& bFormat);
};

using WiderPtr = std::unique_ptr<IWider>;
