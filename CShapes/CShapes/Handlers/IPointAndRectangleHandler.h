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

    virtual RETURN_CODE performOn(std::vector<CShapeWithSize>& inCache) = 0;
    virtual RETURN_CODE perform(std::vector<CShapeWithSize>& inCache) = 0;
    virtual RETURN_CODE performOn(std::vector<CPointWithSize>& inCache) = 0;
    virtual RETURN_CODE perform(std::vector<CPointWithSize>& inCache) = 0;

    virtual RETURN_CODE performOn(
        std::vector<CPointWithSize>& inPointCache,
        std::vector<CShapeWithSize>& inRectangleCache) = 0;
    virtual RETURN_CODE perform(
        std::vector<CPointWithSize>& inPointCache,
        std::vector<CShapeWithSize>& inRectangleCache) = 0;

    virtual const int getProperAmountOfArgs() = 0;
    virtual std::string getProperTypesOfArgs() = 0;
};