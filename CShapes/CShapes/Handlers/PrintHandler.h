#pragma once

#include <vector>
#include <string>

#include "IPointHandler.h"

class CPrintHandler final : public IPointHandler
{

public:
    CPrintHandler(std::vector<std::string>& inCommand);
protected:
    ERROR_CODE performOn(std::vector<CPointWithSize>& inCache) override;
    const int getProperAmountOfArgs() override;
    std::string getProperTypesOfArgs() override;
};
