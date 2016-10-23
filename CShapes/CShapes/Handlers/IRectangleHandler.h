#pragma once

#include <vector>
#include <string>
#include "../Utils.hpp"

class CPoint;
class IRectangleHandler
{
public:
    IRectangleHandler(std::vector<std::string>& inCommand);
    virtual ~IRectangleHandler();
    ERROR_CODE checkCorrectnessAndPerform(std::vector<CPointWithSize>& inCache);
    virtual ERROR_CODE performOn(std::vector<CPointWithSize>& inCache) = 0;
    virtual const int getProperAmountOfArgs() = 0;
    virtual std::string getProperTypesOfArgs() = 0;
protected:
    std::vector<std::string> wholeCommand_;
};

