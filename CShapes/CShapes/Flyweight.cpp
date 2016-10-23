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

using namespace defaultVals;
using namespace messageLiterals;
using namespace funs;

CPoint** CFlyweight::cache_;
CShape** CFlyweight::shapeCache_;
int CFlyweight::sizeOfPointCache_;
std::map<int, bool> CFlyweight::isInitializedPointCache_;

RETURN_CODE CFlyweight::interpretCommand(std::vector<std::string>& inCommand)
{
    RETURN_CODE returnedCode = RETURN_CODE::ERROR;
    {
        if (inCommand.size() == ZERO)
        {
            return RETURN_CODE::ERROR;
        }

        std::string command(inCommand[idxOf::COMMAND]);
        std::vector<CPointWithSize> pairedPointCache = toVectorOfPairsOfPoints(cache_, sizeOfPointCache_);
        std::vector<CShapeWithSize> pairedShapeCache = toVectorOfPairsOfShapes(shapeCache_, sizeOfPointCache_);

        if (command == GO)
        {
            IPointAndRectangleHandler* evaluate = new CGoHandler(inCommand);
            returnedCode = evaluate->perform(pairedPointCache, pairedShapeCache);
            delete evaluate;
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
    }
    else if(command == CLOSE)
    {
        returnedCode = RETURN_CODE::ERROR;
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
    for (int i = 0; i < DEFAULT_FLYWEIGHT_CACHE_SIZE; i++)
    {
        if (cache_[i] == nullptr)
        {
            delete cache_[i];
            cache_[i] = nullptr;
        }
    }
    cache_ = nullptr;
}

CFlyweight::CFlyweight()
{
    sizeOfPointCache_ = DEFAULT_FLYWEIGHT_CACHE_SIZE;
    cache_ = new CPoint*[sizeOfPointCache_];
    for (int i = 0; i < sizeOfPointCache_; i++)
    {
        isInitializedPointCache_[i] = false;
    }
}

CFlyweight::CFlyweight(int inCacheSize)
{
    sizeOfPointCache_ = inCacheSize;
    cache_ = new CPoint*[sizeOfPointCache_];
    for (int i = 0; i < sizeOfPointCache_; i++)
    {
        isInitializedPointCache_[i] = false;
    }
}

CFlyweight::~CFlyweight()
{
    CFlyweight::releaseResources();
}

# pragma endregion
