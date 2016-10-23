#pragma once

#include <vector>
#include <string>

#include "IPointAndRectangleHandler.h"

class CGoHandler : public virtual IPointAndRectangleHandler

{
public:
    CGoHandler(std::vector<std::string>& inCommand);
    virtual ~CGoHandler();
    RETURN_CODE perform(std::vector<CPointWithSize>& inCache) override;
    RETURN_CODE perform(std::vector<CShapeWithSize>& inCache) override;
    RETURN_CODE perform(
        std::vector<CPointWithSize>& inPointCache,
        std::vector<CShapeWithSize>& inRectangleCache) override;
protected:
    RETURN_CODE performOn(
        std::vector<CPointWithSize>& inPointCache,
        std::vector<CShapeWithSize>& inRectangleCache) override;
    RETURN_CODE performOn(std::vector<CPointWithSize>& inCache) override;
    RETURN_CODE performOn(std::vector<CShapeWithSize>& inCache) override;
    const int getProperAmountOfArgs() override;
    std::string getProperTypesOfArgs() override;
};