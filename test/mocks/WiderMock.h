#pragma once
#include <IWider.h>

class WiderMock : public IWider {
public:
    ~WiderMock() = default;

    MOCK_METHOD1(setWidening, void(float radius));

    MOCK_METHOD1(process, std::vector<float>(const std::vector<float>&));
};
