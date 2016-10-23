#pragma once

#include <vector>
#include <string>

#include "IPointAndRectangleHandler.h"

class CGoHandler : public virtual IPointAndRectangleHandler

{
public:
    CGoHandler(std::vector<std::string>& inCommand);
    virtual ~CGoHandler();
    RETURN_CODE perform(CPointWithSize inCache) override;
    RETURN_CODE perform(CShapeWithSize inCache) override;
    RETURN_CODE perform(CPointWithSize inPointCache, CShapeWithSize inRectangleCache) override;
protected:
    RETURN_CODE performOn(CPointWithSize inPointCache, CShapeWithSize inRectangleCache) override;
    RETURN_CODE performOn(CPointWithSize inCache) override;
    RETURN_CODE performOn(CShapeWithSize inCache) override;
    const int getProperAmountOfArgs() override;
    std::string getProperTypesOfArgs() override;
};