#pragma once

#include <vector>
#include <string>

#include "IHandler.h"

class CCreateHandler final : public IHandler
{
public:
    CCreateHandler(std::vector<std::string>& inCommand);
protected:
    ERROR_CODE performOn(std::vector<CPointWithSize>& inCache) override;
    const int getProperAmountOfArgs() override;
    std::string getProperTypesOfArgs() override;
};
