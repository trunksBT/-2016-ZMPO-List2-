#include "stdafx.h"
#include "Rectangle.h"
#include "Utils.hpp"
#include <iostream>
#include <limits>
#include <sstream>
#include "Logger.h"

using namespace defaultVals;
using namespace funs;
using namespace typeLiterals;

CRectangle::CRectangle(CPoint* inPointFst, CPoint* inPointSnd) : CShape()
{
    pointFst_ = new CPoint(*inPointFst);
    pointSnd_ = new CPoint(*inPointSnd);
    Logger::info()
        << CTOR_ARG1_PRE_PRINT
        << RECTANGLE
        << POST_PRINT;
}

CRectangle::CRectangle(const CRectangle& inVal)
{
    deepCopy(inVal);
    Logger::info()
        << CTOR_ARG1_PRE_PRINT
        << RECTANGLE
        << POST_PRINT;
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

