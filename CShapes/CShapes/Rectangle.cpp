#include "stdafx.h"
#include "Rectangle.h"
#include "Point.hpp"
#include "Utils.hpp"
#include <iostream>
#include <limits>
#include <sstream>
#include "Logger.h"
#include <cmath>

using namespace defaultVals;
using namespace funs;
using namespace typeLiterals;
using namespace flags;

CRectangle::CRectangle(CPoint* inPointFst, CPoint* inPointSnd) : CShape()
{
    if (PRINT_CTORS)
    {
        Logger::info()
            << CTOR_ARG1_PRE_PRINT
            << RECTANGLE
            << POST_PRINT;
    }
    pointFst_ = new CPoint(*inPointFst);
    pointSnd_ = new CPoint(*inPointSnd);
}

CRectangle::CRectangle(double fstX, double fstY, double sndX, double sndY)
{
    if (PRINT_CTORS)
    {
        Logger::info()
            << CTOR_ARG1_PRE_PRINT
            << RECTANGLE
            << POST_PRINT;
    }
    pointFst_ = new CPoint(fstX, fstY);
    pointSnd_ = new CPoint(sndX, sndY);
}

CRectangle::CRectangle(const CRectangle& inVal)
{
    if (PRINT_CTORS)
    {
        Logger::info()
            << CTOR_COPY_PRE_PRINT
            << RECTANGLE
            << POST_PRINT;
    }
    deepCopy(inVal);
}

void CRectangle::deepCopy(const CRectangle& inVal)
{
    pointFst_ = new CPoint(*inVal.pointFst_);
    pointSnd_ = new CPoint(*inVal.pointSnd_);
}

CRectangle::~CRectangle()
{
    if (PRINT_CTORS)
    {
        Logger::info()
            << DTOR_PRE_PRINT
            << RECTANGLE
            << POST_PRINT;
    }
    deallocateMemory();
}

std::pair<CODE,double> CRectangle::field()
{
    double fstX = pointFst_->getX();
    double fstY = pointFst_->getY();

    double sndX = pointSnd_->getX();
    double sndY = pointSnd_->getY();

    double segmentFstLength = 0.0;
    double segmentSndLength = 0.0;
    double finalField = 0.0;
    if (isSegmentToBig(fstX, sndX) && isSegmentToBig(fstY, sndY))
    {
        return{ CODE::ERROR, 0.0 };
    }
    else
    {
        segmentFstLength = abs(fstX - sndX);
        segmentSndLength = abs(fstY - sndY);
    }

    if (isDoubleOverflow(segmentFstLength, segmentSndLength))
    {
        return{ CODE::ERROR, 0.0 };
    }
    else
    {
        finalField = segmentFstLength * segmentSndLength;
    }

    return{ CODE::DONE, finalField };
}

CRectangle* CRectangle::buildNewObj(CPoint* inPointFst, CPoint* inPointSnd)
{
    return new CRectangle(inPointFst, inPointSnd);
}

CRectangle* CRectangle::buildNewObj(double fstX, double fstY, double sndX, double sndY)
{
    return new CRectangle(fstX, fstY, sndX, sndY);
}

CRectangle* CRectangle::buildNewObj(CRectangle* inObj)
{
    return new CRectangle(*inObj);
}

void CRectangle::deallocateMemory()
{
    delete pointFst_;
    delete pointSnd_;
}

std::string CRectangle::getType()
{
    return RECTANGLE;
}

std::string CRectangle::toString()
{
    std::stringstream retVal;
    retVal
        << PRE_PRINT << RECTANGLE << BRACKET_OPEN
        << pointFst_->toString()
        << COMMA_SPACE
        << pointSnd_->toString()
        << BRACKET_CLOSE;

    return retVal.str();
}

double CRectangle::fstGetX()
{
    return pointFst_->getX();
}

double CRectangle::fstGetY()
{
    return pointFst_->getY();
}

double CRectangle::sndGetX()
{
    return pointSnd_->getX();
}

double CRectangle::sndGetY()
{
    return pointSnd_->getY();
}

