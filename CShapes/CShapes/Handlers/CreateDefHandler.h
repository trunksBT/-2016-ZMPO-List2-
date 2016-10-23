#pragma once

#include <vector>
#include <string>
#include "../Utils.hpp"
#include "IHandler.h"

class CCreateDefHandler final : public IHandler
{
public:
    CCreateDefHandler(std::vector<std::string>& inCommand);
protected:
    ERROR_CODE performOn(std::vector<CTableWithSize>& inCache) override;
    const int getProperAmountOfArgs() override;
    std::string getProperTypesOfArgs() override;
};
