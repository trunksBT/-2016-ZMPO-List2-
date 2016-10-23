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
    virtual RETURN_CODE performOn(std::vector<CPointWithSize>& inCache) = 0;
    virtual RETURN_CODE perform(std::vector<CPointWithSize>& inCache) = 0;
    virtual const int getProperAmountOfArgs() = 0;
    virtual std::string getProperTypesOfArgs() = 0;
};

