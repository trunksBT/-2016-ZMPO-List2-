#include "stdafx.h"
#include "Rectangle.h"
#include "Point.hpp"
#include "Utils.hpp"
#include <iostream>
#include <limits>
#include <sstream>
#include "Logger.h"

using namespace defaultVals;
using namespace funs;
using namespace typeLiterals;

CRectangle::CRectangle(int value) : CShape()
{
    val = value;
}


CRectangle::CRectangle(CPoint* inPointFst, CPoint* inPointSnd) : CShape()
{
    Logger::info()
        << CTOR_ARG1_PRE_PRINT
        << RECTANGLE
        << POST_PRINT;
    pointFst_ = new CPoint(*inPointFst);
    pointSnd_ = new CPoint(*inPointSnd);
}

CRectangle::CRectangle(double fstX, double fstY, double sndX, double sndY)
{
    Logger::info()
        << CTOR_ARG1_PRE_PRINT
        << RECTANGLE
        << POST_PRINT;
    pointFst_ = new CPoint(fstX, fstY);
    pointSnd_ = new CPoint(sndX, sndY);
}

CRectangle::CRectangle(const CRectangle& inVal)
{
    Logger::info()
        << CTOR_COPY_PRE_PRINT
        << RECTANGLE
        << POST_PRINT;
    deepCopy(inVal);
}

void CRectangle::deepCopy(const CRectangle& inVal)
{
    pointFst_ = new CPoint(*inVal.pointFst_);
    pointSnd_ = new CPoint(*inVal.pointSnd_);
}

CRectangle::~CRectangle()
{
    Logger::info()
        << DTOR_PRE_PRINT
        << RECTANGLE
        << POST_PRINT;
    deallocateMemory();
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

CRectangle* CRectangle::buildNewObj(int inVal)
{
    return new CRectangle(inVal);
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

