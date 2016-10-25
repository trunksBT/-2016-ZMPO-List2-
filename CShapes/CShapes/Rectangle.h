#pragma once

#include <string>
#include <vector>
#include "Shape.h"
#include "Utils.hpp"
#include <iostream>
#include <limits>
#include <sstream>
#include "Logger.h"

using namespace defaultVals;
using namespace funs;
using namespace typeLiterals;
using namespace flags;

class CPoint;
class CRectangle : public CShape
{
public:
    CRectangle(CPoint* inPointFst, CPoint* inPointSnd)
        : objectFst_(inPointFst->getX(), inPointFst->getY())
        , objectSnd_(inPointSnd->getX(), inPointSnd->getY())
    {
        if (PRINT_CTORS)
        {
            Logger::info()
                << CTOR_ARG1_PRE_PRINT
                << RECTANGLE
                << POST_PRINT;
        }
    };
    CRectangle(double fstX, double fstY, double sndX, double sndY)
        : objectFst_(CPoint(fstX, fstY)), objectSnd_(CPoint(sndX, sndY))
    {
        if (PRINT_CTORS)
        {
            Logger::info()
                << CTOR_ARG1_PRE_PRINT
                << RECTANGLE
                << POST_PRINT;
        }
    };
    CRectangle(const CRectangle& inVal)
        : objectFst_(inVal.objectFst_)
        , objectSnd_(inVal.objectSnd_)
    {
        if (PRINT_CTORS)
        {
            Logger::info()
                << CTOR_COPY_PRE_PRINT
                << RECTANGLE
                << POST_PRINT;
        }
    };

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
    CPoint objectFst_;
    CPoint objectSnd_;
};
