#pragma once

#include <vector>
#include <string>
#include "../Utils.hpp"
#include "IHandler.h"

class CPoint;
class IShapeHandler : public virtual IHandler
{
public:
    IShapeHandler(std::vector<std::string>& inCommand);
    virtual ~IShapeHandler();
    virtual RETURN_CODE performOn(std::vector<CShapeWithSize>& inCache) = 0;
    virtual RETURN_CODE perform(std::vector<CShapeWithSize>& inCache) = 0;
    virtual const int getProperAmountOfArgs() = 0;
    virtual std::string getProperTypesOfArgs() = 0;
};

