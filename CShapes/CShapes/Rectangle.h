#pragma once

#include <string>
#include <vector>
#include "Shape.h"
#include "Utils.hpp"

class CPoint;
class CRectangle : public CShape
{
public:
    explicit CRectangle(CPoint* inPointFst, CPoint* inPointSnd);
    explicit CRectangle(double fstX, double fstY, double sndX, double sndY);
    CRectangle(const CRectangle& inVal);
    virtual ~CRectangle();
public:
    double fstGetX();
    double fstGetY();
    double sndGetX();
    double sndGetY();
public:
    std::string toString() override;
    std::string getType() override;
    std::pair<CODE, double> field();
public:
    static CRectangle* buildNewObj(CPoint* inPointFst, CPoint* inPointSnd);
    static CRectangle* buildNewObj(double fstX, double fstY, double sndX, double sndY);
    static CRectangle* buildNewObj(CRectangle* inObj);
private:
    void deepCopy(const CRectangle& inVal);
    void deallocateMemory();
private:
    CPoint* pointFst_;
    CPoint* pointSnd_;
    int val;
};
