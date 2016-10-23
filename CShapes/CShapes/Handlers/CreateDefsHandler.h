#pragma once

#include <vector>
#include <string>

#include "IHandler.h"

class CCreateDefsHandler final : public IHandler
{
public:
    CCreateDefsHandler(std::vector<std::string>& inCommand);
protected:
    ERROR_CODE performOn(std::vector<CPointWithSize>& inCache) override;
    const int getProperAmountOfArgs() override;
    std::string getProperTypesOfArgs() override;
};