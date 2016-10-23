#pragma once

#include <vector>
#include <string>

#include "IHandler.h"

class CGetValueHandler final : public IHandler
{
public:
    CGetValueHandler(std::vector<std::string>& inCommand);
protected:
    ERROR_CODE performOn(std::vector<CTableWithSize>& inCache) override;
    const int getProperAmountOfArgs() override;
    std::string getProperTypesOfArgs() override;
};
