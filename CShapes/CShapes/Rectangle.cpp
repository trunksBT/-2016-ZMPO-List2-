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

CRectangle::CRectangle()
{
    name_ = DEFAULT_TABLE_NAME;
    size_ = DEFAULT_AXIS_VAL;
    allocateMemory(size_);
    initTable(memory_, size_, DEFAULT_TABLE_VAL);
    Logger::info() << CTOR_DEFAULT_PRE_PRINT << name_ << POST_PRINT;
}

CRectangle::CRectangle(int inSize)
{
    name_ = DEFAULT_TABLE_NAME;
    size_ = inSize;
    allocateMemory(size_);
    initTable(memory_, size_, DEFAULT_TABLE_VAL);
    Logger::info() << CTOR_ARG1_PRE_PRINT << name_ << POST_PRINT;
}

CRectangle::CRectangle(int inSize, int initValue)
{
    name_ = DEFAULT_TABLE_NAME;
    size_ = inSize;
    allocateMemory(size_);
    initTable(memory_, size_, initValue);
    Logger::info() << CTOR_ARG1_PRE_PRINT << name_ << POST_PRINT;
}

CRectangle::CRectangle(std::string inName)
{
    name_ = inName;
    size_ = DEFAULT_AXIS_VAL;
    allocateMemory(size_);
    initTable(memory_, size_, DEFAULT_TABLE_VAL);
    Logger::info() << CTOR_ARG1_PRE_PRINT << name_ << POST_PRINT;
}

CRectangle::CRectangle(int inSize, std::string inName)
{
    name_ = inName;
    size_ = inSize;
    allocateMemory(size_);
    initTable(memory_, size_, DEFAULT_TABLE_VAL);
    Logger::info() << CTOR_ARG1_PRE_PRINT << name_ << POST_PRINT;
}

CRectangle::CRectangle(CRectangle& inVal)
{
    copyCtor(inVal);
}

CRectangle* CRectangle::clone()
{
    CRectangle* newObject = new CRectangle(*this);
    newObject->setName(this->getName());
    return newObject;
}

void CRectangle::initTable()
{
    initTable(memory_, DEFAULT_AXIS_VAL, DEFAULT_TABLE_VAL);
}


void CRectangle::initTable(int* table, int size, int defaultVal)
{
    for (int i = 0; i < size; i++)
    {
        table[i] = int(defaultVal);
    }
}

void CRectangle::copyCtor(CRectangle& inVal)
{
    name_ = inVal.name_;
    size_ = inVal.size_;
    name_.append(POST_COPIED_NAME);
    allocateMemory(size_);
    deepCopy(inVal);
    Logger::info() << CTOR_COPY_PRE_PRINT << name_ << POST_PRINT;
}

CRectangle& CRectangle::operator=(CRectangle& inObj)
{
    delete[] memory_;
    copyCtor(inObj);
    return *this;
}

void CRectangle::setSize(int inNewSize)
{
    if (size_ != inNewSize)
    {
        int* newTable = new int[inNewSize];
        if (size_ < inNewSize)
        {
            initTable(newTable, inNewSize, DEFAULT_TABLE_VAL);
        }
        for (int i = 0; i < size_ && i < inNewSize; i++)
        {
            newTable[i] = int(memory_[i]);
        }
        delete[] memory_;
        memory_ = newTable;
        size_ = inNewSize;
    }
}

CRectangle* CRectangle::buildNewObj()
{
    return new CRectangle();
}

CRectangle* CRectangle::buildNewObj(CRectangle& inVal)
{
    return new CRectangle(inVal);
}

CRectangle* CRectangle::buildNewObj(int inSize)
{
    return new CRectangle(inSize);
}

CRectangle* CRectangle::buildNewObj(int inSize, int inInitValue)
{
    return new CRectangle(inSize, inInitValue);
}

CRectangle* CRectangle::buildNewObj(int inSize, std::string inName)
{
    return new CRectangle(inSize, inName);
}

void CRectangle::allocateMemory(int size)
{
    memory_ = new int[size];
}

void CRectangle::deepCopy(CRectangle& inVal)
{
    for (int i = 0; i < inVal.size_; i++)
    {
        memory_[i] = int(inVal.memory_[i]);
    }
}

CRectangle::~CRectangle()
{
    deallocateMemory();
    Logger::info() << DTOR_PRE_PRINT << name_ << POST_PRINT;
}

void CRectangle::setName(std::string inName)
{
    name_ = std::move(inName);
}

void CRectangle::deallocateMemory()
{
    delete[] memory_;
}

void CRectangle::setVal(int idx, int newVal)
{
    if (isProperIdx(idx, size_))
    {
        memory_[idx] = newVal;
    }
}

int CRectangle::getVal(int idx) const
{
    int retVal = std::numeric_limits<int>::min();
    if (isProperIdx(idx, size_))
    {
        retVal = memory_[idx];
    }
    return retVal;
}

int CRectangle::getSize() const
{
    return size_;
}

std::string CRectangle::getName() const
{
    return std::string(name_);
}

std::string CRectangle::getType()
{
    return RECTANGLE;
}

std::string CRectangle::toString()
{
    std::stringstream retVal;
    retVal << getType() << SEPARATOR;
    retVal << BRACKET_OPEN << name_;
    retVal << SPACE << LEN << SEPARATOR << size_;
    retVal << SPACE << VALUES << SEPARATOR;

    for (int i = 0; i < size_; i++)
    {
        retVal << memory_[i] << COMMA_SPACE;
    }

    std::string stringedStream(retVal.str());
    stringedStream = stringedStream.substr(ZERO, stringedStream.size() - TWO);

    return std::move(stringedStream + std::string(BRACKET_CLOSE));
}

