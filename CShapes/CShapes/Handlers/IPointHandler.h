#pragma once

#include <vector>
#include <string>
#include "../Utils.hpp"
#include "IHandler.h"

class CPoint;
class IPointHandler : public virtual IHandler
{
public:
    IPointHandler(std::vector<std::string>& inCommand);
    virtual ~IPointHandler();
    virtual CODE performOn(CPointWithSize inCache) = 0;
    virtual CODE perform(CPointWithSize inCache) = 0;
    virtual const int getProperAmountOfArgs() = 0;
    virtual std::string getProperTypesOfArgs() = 0;
};

