#pragma once

#include <vector>
#include <string>

#include "IPointHandler.h"
#include "IShapeHandler.h"

class IPointAndRectangleHandler : public virtual IPointHandler, public  virtual IShapeHandler
{
public:
    IPointAndRectangleHandler(std::vector<std::string>& inCommand);
    virtual ~IPointAndRectangleHandler();

    virtual RETURN_CODE performOn(CShapeWithSize inCache) = 0;
    virtual RETURN_CODE perform(CShapeWithSize inCache) = 0;
    virtual RETURN_CODE performOn(CPointWithSize inCache) = 0;
    virtual RETURN_CODE perform(CPointWithSize inCache) = 0;

    virtual RETURN_CODE performOn(
        CPointWithSize inPointCache,
        CShapeWithSize inRectangleCache) = 0;
    virtual RETURN_CODE perform(
        CPointWithSize inPointCache,
        CShapeWithSize inRectangleCache) = 0;

    virtual const int getProperAmountOfArgs() = 0;
    virtual std::string getProperTypesOfArgs() = 0;
};