#include "stdafx.h"
#include "Point.hpp"
#include "Utils.hpp"
#include <iostream>
#include <limits>
#include <sstream>
#include "Logger.h"

using namespace defaultVals;
using namespace funs;
using namespace typeLiterals;

CPoint::CPoint(double xAxis, double yAxis) : CShape()
{
    xAxis_ = new double(xAxis);
    yAxis_ = new double(yAxis);
    Logger::info()
        << CTOR_ARG1_PRE_PRINT 
        << X << SEPARATOR << std::to_string(*xAxis_)
        << COMMA_SPACE
        << Y << SEPARATOR << std::to_string(*yAxis_)
        << POST_PRINT;
}

CPoint::CPoint(const CPoint& inVal)
{
    deepCopy(inVal);
    Logger::info()
        << CTOR_COPY_PRE_PRINT
        << X << SEPARATOR << std::to_string(*xAxis_)
        << COMMA_SPACE
        << Y << SEPARATOR << std::to_string(*yAxis_)
        << POST_PRINT;
}

void CPoint::deepCopy(const CPoint& inVal)
{
    xAxis_ = new double(*inVal.xAxis_);
    yAxis_ = new double(*inVal.yAxis_);
}

CPoint::~CPoint()
{
    Logger::info()
        << DTOR_PRE_PRINT
        << X << SEPARATOR << std::to_string(*xAxis_)
        << COMMA_SPACE
        << Y << SEPARATOR << std::to_string(*yAxis_)
        << POST_PRINT;
    deallocateMemory();
}

CPoint* CPoint::buildNewObj(double xAxis, double yAxis)
{
    return new CPoint(xAxis, yAxis);
}

CPoint* CPoint::buildNewObj(CPoint* inObj)
{
    return new CPoint(*inObj);
}

void CPoint::deallocateMemory()
{
    delete xAxis_;
    delete yAxis_;
}

void CPoint::setX(double newX)
{
    delete xAxis_;
    xAxis_ = new double(newX);
}

void CPoint::setY(double newY)
{
    delete yAxis_;
    yAxis_ = new double(newY);
}

double CPoint::getX() const
{
    return double(*xAxis_);
}

double CPoint::getY() const
{
    return double(*yAxis_);
}

std::string CPoint::getType()
{
    return POINT;
}

std::string CPoint::toString()
{
    std::stringstream retVal;
    retVal
        << PRE_PRINT << POINT << BRACKET_OPEN
        << X << SEPARATOR << std::to_string(*xAxis_)
        << COMMA_SPACE
        << Y << SEPARATOR << std::to_string(*yAxis_)
        << BRACKET_CLOSE;

    return retVal.str();
}

