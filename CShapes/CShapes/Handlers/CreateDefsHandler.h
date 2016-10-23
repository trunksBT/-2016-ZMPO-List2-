#pragma once

#include <vector>
#include <string>

#include "IPointHandler.h"
#include "IShapeHandler.h"

class CCreateDefsHandler : public virtual IPointHandler, public  virtual IShapeHandler
{
public:
    CCreateDefsHandler(std::vector<std::string>& inCommand);
    virtual ~CCreateDefsHandler();
    RETURN_CODE perform(std::vector<CPointWithSize>& inCache) override;
    RETURN_CODE perform(std::vector<CShapeWithSize>& inCache) override;
protected:
    RETURN_CODE performOn(std::vector<CPointWithSize>& inCache) override;
    RETURN_CODE performOn(std::vector<CShapeWithSize>& inCache) override;
    const int getProperAmountOfArgs() override;
    std::string getProperTypesOfArgs() override;
};