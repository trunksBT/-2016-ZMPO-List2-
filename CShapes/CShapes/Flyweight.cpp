#include "stdafx.h"
#include <iostream>
#include "Flyweight.h"
#include "Utils.hpp"
#include "Handlers/CreateHandler.h"
#include "Handlers/CreateDefHandler.h"
#include "Handlers/CreateDefsHandler.h"
#include "Handlers/RemoveAllHandler.h"
#include "Handlers/RemoveHandler.h"
#include "Handlers/SetValueHandler.h"
#include "Handlers/GetValueHandler.h"
#include "Handlers/CreateCopyHandler.h"
#include "Handlers/PrintHandler.h"
#include "Handlers/PrintAllHandler.h"
#include "Handlers/HelpHandler.h"
#include "UtilsForMT.h"
#include "Logger.h"

using namespace defaultVals;
using namespace messageLiterals;
using namespace funs;

CShape** CFlyweight::pointCache_;
int CFlyweight::sizeOfPointCache_;
std::map<int, bool> CFlyweight::isInitializedPointCache_;

CShape** CFlyweight::shapeCache_;
int CFlyweight::sizeOfShapeCache_;
std::map<int, bool> CFlyweight::isInitializedShapeCache_;

RETURN_CODE CFlyweight::interpretCommand(std::vector<std::string>& inCommand)
{
    RETURN_CODE returnedCode = RETURN_CODE::ERROR;
    {
        if (inCommand.size() == ZERO)
        {
            return RETURN_CODE::ERROR;
        }

        std::string command(inCommand[idxOf::COMMAND]);
        CPointWithSize pairedPointCache = { 
            reinterpret_cast<CPoint**>(pointCache_),
            sizeOfPointCache_,
            isInitializedPointCache_
        };

        CShapeWithSize pairedShapeCache = 
        {
        shapeCache_,
        sizeOfPointCache_,
        isInitializedShapeCache_ 
        };

        if (command == GO)
        {
            IPointAndRectangleHandler* evaluate = new CGoHandler(inCommand);
            returnedCode = evaluate->perform(pairedPointCache, pairedShapeCache);
            delete evaluate;
        }
        else if (command == CLOSE)
        {
            returnedCode = RETURN_CODE::CLOSE;
        }
    }
    /*if(command == CREATE)
    {
        CCreateHandler evaluate(inCommand);
        returnedCode = evaluate.checkCorrectnessAndPerform(cache_);
    }
    else if(command == CREATE_DEF)
    {
        CCreateDefHandler evaluate(inCommand);
        returnedCode = evaluate.checkCorrectnessAndPerform(cache_);
    }

    else if(command == CREATE_COPY)
    {
        CCreateCopyHandler evaluate(inCommand);
        returnedCode = evaluate.checkCorrectnessAndPerform(cache_);
    }
    else if(command == REMOVE_ALL)
    {
        CRemoveAllHandler evaluate(inCommand);
        returnedCode = evaluate.checkCorrectnessAndPerform(cache_);
    }
    else if(command == SET_VALUE)
    {
        CSetValueHandler evaluate(inCommand);
        returnedCode = evaluate.checkCorrectnessAndPerform(cache_);
    }
    else if(command == GET_VALUE)
    {
        CGetValueHandler evaluate(inCommand);
        returnedCode = evaluate.checkCorrectnessAndPerform(cache_);
    }
    else if(command == PRINT)
    {
        CPrintHandler evaluate(inCommand);
        returnedCode = evaluate.checkCorrectnessAndPerform(cache_);
    }
    else if (command == DELETE)
    {
        CRemoveHandler evaluate(inCommand);
        returnedCode = evaluate.checkCorrectnessAndPerform(cache_);
    }
    else if(command == PRINT_ALL)
    {
        CPrintAllHandler evaluate(inCommand);
        returnedCode = evaluate.checkCorrectnessAndPerform(cache_);
    }
    else if(command == HELP)
    {
        CHelpHandler evaluate(inCommand);
        returnedCode = evaluate.checkCorrectnessAndPerform(cache_);
    }*/

    //else
    //{
    //    returnedCode = returnResultCode(RETURN_CODE::ERROR);
    //}

    return returnedCode;
}

#pragma region ********** CTORS_DTORS **********

void CFlyweight::releaseResources()
{
    for (int i = 0; i < DEFAULT_FLYWEIGHT_CACHE_SIZE && isInitializedPointCache_[i]; i++)
    {
        if (pointCache_[i] == nullptr)
        {
            delete pointCache_[i];
            pointCache_[i] = nullptr;
        }
    }
    pointCache_ = nullptr;

    for (int i = 0; i < DEFAULT_FLYWEIGHT_CACHE_SIZE && isInitializedShapeCache_[i]; i++)
    {
        if (shapeCache_[i] == nullptr)
        {
            delete shapeCache_[i];
            shapeCache_[i] = nullptr;
        }
    }
    shapeCache_ = nullptr;
}

void CFlyweight::initPointCache(int inCacheSize)
{
    sizeOfPointCache_ = inCacheSize;
    pointCache_ = nullptr;
    for (int i = 0; i < sizeOfPointCache_; i++)
    {
        isInitializedPointCache_[i] = false;
    }

    pointCache_ = new CShape*[sizeOfPointCache_];
}

void CFlyweight::initShapesCache(int inCacheSize)
{
    sizeOfShapeCache_ = inCacheSize;
    shapeCache_ = nullptr;
    for (int i = 0; i < sizeOfPointCache_; i++)
    {
        isInitializedShapeCache_[i] = false;
    }

    shapeCache_ = new CShape*[sizeOfShapeCache_];
}

CFlyweight::CFlyweight()
{
    initPointCache(DEFAULT_FLYWEIGHT_CACHE_SIZE);
    initPointCache(DEFAULT_FLYWEIGHT_CACHE_SIZE);
}

CFlyweight::CFlyweight(int inPointCacheSize, int inShapeCacheSize)
{
    initPointCache(inPointCacheSize);
    initPointCache(inShapeCacheSize);
}

CFlyweight::~CFlyweight()
{
    CFlyweight::releaseResources();
}

# pragma endregion
