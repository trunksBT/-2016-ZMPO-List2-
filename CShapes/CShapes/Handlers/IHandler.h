#pragma once

#include <vector>
#include <string>
#include "../Utils.hpp"

class CTable;
class IHandler
{
public:
    IHandler(std::vector<std::string>& inCommand);
    virtual ~IHandler();
    ERROR_CODE checkCorrectnessAndPerform(std::vector<CTableWithSize>& inCache);
    virtual ERROR_CODE performOn(std::vector<CTableWithSize>& inCache) = 0;
    virtual const int getProperAmountOfArgs() = 0;
    virtual std::string getProperTypesOfArgs() = 0;
protected:
    std::vector<std::string> wholeCommand_;
};

