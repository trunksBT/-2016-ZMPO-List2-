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
int CFlyweight::pointCacheSize_;
std::map<int, bool> CFlyweight::pointCacheIsInitialized_;

CShape** CFlyweight::shapeCache_;
int CFlyweight::shapeCacheSize_;
std::map<int, bool> CFlyweight::shapeCacheIsInitialized_;

CODE CFlyweight::interpretCommand(std::vector<std::string>& inCommand)
{
    CODE returnedCode = CODE::ERROR;
    {
        if (inCommand.size() == ZERO)
        {
            return CODE::ERROR;
        }

        std::string command(inCommand[idxOf::COMMAND]);
        CPointWithSize pairedPointCache = { 
            reinterpret_cast<CPoint**>(pointCache_),
            pointCacheSize_,
            pointCacheIsInitialized_
        };

        CShapeWithSize pairedShapeCache = 
        {
            shapeCache_,
            shapeCacheSize_,
            shapeCacheIsInitialized_ 
        };

        if (command == GO)
        {
            IPointAndRectangleHandler* evaluate = new CGoHandler(inCommand);
            returnedCode = evaluate->checkArgsAndPerform(pairedPointCache, pairedShapeCache);
        }
        else if (command == PRINT_ALL)
        {
            IPointAndRectangleHandler* evaluate = new CPrintAllHandler(inCommand);
            returnedCode = evaluate->checkArgsAndPerform(pairedPointCache, pairedShapeCache);
        }
        else if (command == CLOSE)
        {
            returnedCode = CODE::CLOSE;
        }
    }
    /*if(command == CREATE)
    {
        CCreateHandler evaluate(inCommand);
        returnedCode = evaluate.checkTypeAndAmountOfArgs(cache_);
    }
    else if(command == CREATE_DEF)
    {
        CCreateDefHandler evaluate(inCommand);
        returnedCode = evaluate.checkTypeAndAmountOfArgs(cache_);
    }

    else if(command == CREATE_COPY)
    {
        CCreateCopyHandler evaluate(inCommand);
        returnedCode = evaluate.checkTypeAndAmountOfArgs(cache_);
    }
    else if(command == REMOVE_ALL)
    {
        CRemoveAllHandler evaluate(inCommand);
        returnedCode = evaluate.checkTypeAndAmountOfArgs(cache_);
    }
    else if(command == SET_VALUE)
    {
        CSetValueHandler evaluate(inCommand);
        returnedCode = evaluate.checkTypeAndAmountOfArgs(cache_);
    }
    else if(command == GET_VALUE)
    {
        CGetValueHandler evaluate(inCommand);
        returnedCode = evaluate.checkTypeAndAmountOfArgs(cache_);
    }
    else if(command == PRINT)
    {
        CPrintHandler evaluate(inCommand);
        returnedCode = evaluate.checkTypeAndAmountOfArgs(cache_);
    }
    else if (command == DELETE)
    {
        CRemoveHandler evaluate(inCommand);
        returnedCode = evaluate.checkTypeAndAmountOfArgs(cache_);
    }

    else if(command == HELP)
    {
        CHelpHandler evaluate(inCommand);
        returnedCode = evaluate.checkTypeAndAmountOfArgs(cache_);
    }*/

    //else
    //{
    //    returnedCode = returnResultCode(CODE::ERROR);
    //}

    return returnedCode;
}

#pragma region ********** CTORS_DTORS **********

void CFlyweight::releaseResources()
{
    for (int i = 0; i < pointCacheSize_; i++)
    {
        if (pointCacheIsInitialized_[i] && pointCache_[i] == nullptr)
        {
            delete pointCache_[i];
            pointCache_[i] = nullptr;
        }
    }
    delete[] pointCache_;
    pointCache_ = nullptr;

    for (int i = 0; i < shapeCacheSize_; i++)
    {
        if ( shapeCacheIsInitialized_[i] && shapeCache_[i] == nullptr )
        {
            delete shapeCache_[i];
            shapeCache_[i] = nullptr;
        }
    }
    delete[] shapeCache_;
    shapeCache_ = nullptr;
}

void CFlyweight::initPointCache(int inCacheSize)
{
    if (inCacheSize >= ZERO)
    {
        pointCacheSize_ = inCacheSize;
        pointCache_ = nullptr;
        for (int i = 0; i < pointCacheSize_; i++)
        {
            pointCacheIsInitialized_[i] = false;
        }

        pointCache_ = new CShape*[pointCacheSize_];
    }
}

void CFlyweight::initShapeCache(int inCacheSize)
{
    if (inCacheSize >= ZERO)
    {
        shapeCacheSize_ = inCacheSize;
        shapeCache_ = nullptr;
        for (int i = 0; i < shapeCacheSize_; i++)
        {
            shapeCacheIsInitialized_[i] = false;
        }

        shapeCache_ = new CShape*[shapeCacheSize_];
    }
}

CFlyweight::CFlyweight()
{
    initPointCache(ZERO);
    initPointCache(ZERO);
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

void CFlyweight::setPointCacheSize(int inSize)
{
    std::cout << "Zmienilem sie PointSize" << std::endl;
    pointCacheSize_ = inSize;
}
void CFlyweight::setShapeCacheSize(int inSize)
{
    std::cout << "Zmienilem sie ShapeSize" << std::endl;
    shapeCacheSize_ = inSize;
}

void CFlyweight::updateIsInitializedPointCache(int idx, bool newVal)
{
    pointCacheIsInitialized_[idx] = newVal;
}

void CFlyweight::updateIsInitializedShapeCache(int idx, bool newVal)
{
    shapeCacheIsInitialized_[idx] = newVal;
}

void CFlyweight::updatePointCache(CShape** newPointCache)
{
    pointCache_ = newPointCache;
}

void CFlyweight::updateShapeCache(CShape** newShapeCache)
{
    shapeCache_ = newShapeCache;
}

# pragma endregion
