#pragma once

#include <vector>
#include <string>

#include "IPointAndRectangleHandler.h"

class CGoHandler : public virtual IPointAndRectangleHandler

{
public:
    CGoHandler(std::vector<std::string>& inCommand);
    virtual ~CGoHandler();
    CODE perform(CPointWithSize inCache) override;
    CODE perform(CShapeWithSize inCache) override;
    CODE perform(CPointWithSize inPointCache, CShapeWithSize inRectangleCache) override;
protected:
    CODE performOn(CPointWithSize inPointCache, CShapeWithSize inRectangleCache) override;
    CODE performOn(CPointWithSize inCache) override;
    CODE performOn(CShapeWithSize inCache) override;
    const int getProperAmountOfArgs() override;
    std::string getProperTypesOfArgs() override;
};