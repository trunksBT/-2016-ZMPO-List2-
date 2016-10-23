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

CPoint::CPoint(double xAxis, double yAxis)
{

}

CPoint::CPoint(int inSize) : CShape()
{
    name_ = DEFAULT_TABLE_NAME;
    size_ = inSize;
    allocateMemory(size_);
    initTable(memory_, size_, DEFAULT_TABLE_VAL);
    Logger::info() << CTOR_ARG1_PRE_PRINT<< name_ << POST_PRINT;
}

CPoint::CPoint(int inSize, int initValue) : CShape()
{
    name_ = DEFAULT_TABLE_NAME;
    size_ = inSize;
    allocateMemory(size_);
    initTable(memory_, size_, initValue);
    Logger::info() << CTOR_ARG1_PRE_PRINT << name_ << POST_PRINT;
}

CPoint::CPoint(std::string inName) : CShape()
{
    name_ = inName;
    size_ = DEFAULT_IN_TABLE_SIZE;
    allocateMemory(size_);
    initTable(memory_, size_, DEFAULT_TABLE_VAL);
    Logger::info() << CTOR_ARG1_PRE_PRINT << name_ << POST_PRINT;
}

CPoint::CPoint(int inSize, std::string inName) : CShape()
{
    name_ = inName;
    size_ = inSize;
    allocateMemory(size_);
    initTable(memory_, size_, DEFAULT_TABLE_VAL);
    Logger::info() << CTOR_ARG1_PRE_PRINT << name_ << POST_PRINT;
}

CPoint::CPoint(CPoint& inVal)
{
    copyCtor(inVal);
}

CPoint* CPoint::clone()
{
    CPoint* newObject = new CPoint(*this);
    newObject->setName(this->getName());
    return newObject;
}

void CPoint::initTable()
{
    initTable(memory_, DEFAULT_IN_TABLE_SIZE, DEFAULT_TABLE_VAL);
}


void CPoint::initTable(int* table, int size, int defaultVal)
{
    for(int i = 0; i < size; i++)
    {
        table[i] = int(defaultVal);
    }
}

void CPoint::copyCtor(CPoint& inVal)
{
    name_ = inVal.name_;
    size_ = inVal.size_;
    name_.append(POST_COPIED_NAME);
    allocateMemory(size_);
    deepCopy(inVal);
    Logger::info() << CTOR_COPY_PRE_PRINT << name_ << POST_PRINT;
}

CPoint& CPoint::operator=(CPoint& inObj)
{
    delete[] memory_;
    copyCtor(inObj);
    return *this;
}

void CPoint::setSize(int inNewSize)
{
    if(size_ != inNewSize)
    {
        int* newTable = new int[inNewSize];
        if(size_ < inNewSize)
        {
            initTable(newTable, inNewSize, DEFAULT_TABLE_VAL);
        }
        for(int i = 0; i < size_ && i < inNewSize; i++)
        {
            newTable[i] = int(memory_[i]);
        }
        delete[] memory_;
        memory_ = newTable;
        size_ = inNewSize;
    }
}

CPoint* CPoint::buildNewObj(CPoint& inVal)
{
    return new CPoint(inVal);
}

CPoint* CPoint::buildNewObj(int inSize)
{
    return new CPoint(inSize);
}

CPoint* CPoint::buildNewObj(int inSize, int inInitValue)
{
    return new CPoint(inSize, inInitValue);
}

CPoint* CPoint::buildNewObj(int inSize, std::string inName)
{
    return new CPoint(inSize, inName);
}

void CPoint::allocateMemory(int size)
{
    memory_ = new int[size];
}

void CPoint::deepCopy(CPoint& inVal)
{
    for(int i = 0; i < inVal.size_; i++)
    {
        memory_[i] = int(inVal.memory_[i]);
    }
}

CPoint::~CPoint()
{
    deallocateMemory();
    Logger::info() << DTOR_PRE_PRINT << name_ << POST_PRINT;
}

void CPoint::setName(std::string inName)
{
    name_ = std::move(inName);
}

void CPoint::deallocateMemory()
{
    delete[] memory_;
}

void CPoint::setVal(int idx, int newVal)
{
    if(isProperIdx(idx, size_))
    {
        memory_[idx] = newVal;
    }
}

int CPoint::getVal(int idx) const
{
    int retVal = std::numeric_limits<int>::min();
    if(isProperIdx(idx, size_))
    {
        retVal = memory_[idx];
    }
    return retVal;
}

int CPoint::getSize() const
{
    return size_;
}

std::string CPoint::getName() const
{
    return std::string(name_);
}

std::string CPoint::getType()
{
    return POINT;
}

std::string CPoint::toString()
{
    std::stringstream retVal;
    retVal << getType() << SEPARATOR;
    retVal << BRACKET_OPEN << name_;
    retVal << SPACE << LEN << SEPARATOR << size_;
    retVal << SPACE << VALUES << SEPARATOR;

    for(int i = 0; i < size_; i++)
    {
        retVal << memory_[i] << COMMA_SPACE;
    }

    std::string stringedStream(retVal.str());
    stringedStream = stringedStream.substr(ZERO, stringedStream.size() - TWO);

    return std::move(stringedStream + std::string(BRACKET_ERROR));
}

