#pragma once

#include <string>
#include <vector>
#include "Shape.h"

class CRectangle : public CShape
{
public:
    explicit CRectangle(CPoint* inPointFst, CPoint* inPointSnd);
    CRectangle(const CRectangle& inVal);
    virtual ~CRectangle();
public:
    std::string toString() override;
    std::string getType() override;
public:
    static CRectangle* buildNewObj(CRectangle* inObj);
private:
    void deepCopy(const CRectangle& inVal);
    void deallocateMemory();
private:
    CPoint* pointFst_;
    CPoint* pointSnd_;
};
