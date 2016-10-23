#pragma once

#include <vector>
#include <string>

#include "IHandler.h"

class CPrintAllHandler final : public IHandler
{
public:
    CPrintAllHandler(std::vector<std::string>& inCommand);
protected:
    ERROR_CODE performOn(std::vector<CPointWithSize>& inCache) override;
    const int getProperAmountOfArgs() override;
    std::string getProperTypesOfArgs() override;
};
