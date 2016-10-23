#pragma once

#include <vector>
#include <string>
#include "../Utils.hpp"
#include "IPointHandler.h"

class CCreateDefHandler final : public IPointHandler
{
public:
    CCreateDefHandler(std::vector<std::string>& inCommand);
protected:
    ERROR_CODE performOn(std::vector<CPointWithSize>& inCache) override;
    const int getProperAmountOfArgs() override;
    std::string getProperTypesOfArgs() override;
};
