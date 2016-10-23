#pragma once

#include <vector>
#include <string>
#include "../Utils.hpp"

class CPoint;
class IShapeHandler
{
public:
    IShapeHandler(std::vector<std::string>& inCommand);
    virtual ~IShapeHandler();
    ERROR_CODE checkCorrectnessAndPerform(std::vector<CShapeWithSize>& inCache);
    virtual ERROR_CODE performOn(std::vector<CShapeWithSize>& inCache) = 0;
    virtual const int getProperAmountOfArgs() = 0;
    virtual std::string getProperTypesOfArgs() = 0;
protected:
    std::vector<std::string> wholeCommand_;
};

