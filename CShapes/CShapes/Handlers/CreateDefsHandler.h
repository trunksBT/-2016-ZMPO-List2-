#pragma once

#include <vector>
#include <string>

#include "IPointHandler.h"
#include "IShapeHandler.h"

class CGoHandler : public virtual IPointHandler, public  virtual IShapeHandler
{
public:
    CGoHandler(std::vector<std::string>& inCommand);
    virtual ~CGoHandler();
    RETURN_CODE perform(std::vector<CPointWithSize>& inCache) override;
    RETURN_CODE perform(std::vector<CShapeWithSize>& inCache) override;
protected:
    RETURN_CODE performOn(std::vector<CPointWithSize>& inCache) override;
    RETURN_CODE performOn(std::vector<CShapeWithSize>& inCache) override;
    const int getProperAmountOfArgs() override;
    std::string getProperTypesOfArgs() override;
};