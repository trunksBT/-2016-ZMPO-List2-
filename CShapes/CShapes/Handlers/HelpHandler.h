#pragma once

#include <vector>
#include <string>

#include "IHandler.h"

class CHelpHandler final : public IHandler
{
public:
    CHelpHandler(std::vector<std::string>& inCommand);
protected:
    ERROR_CODE performOn(std::vector<CTableWithSize>& inCache) override;
    const int getProperAmountOfArgs() override;
    std::string getProperTypesOfArgs() override;
};
