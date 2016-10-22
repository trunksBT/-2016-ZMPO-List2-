#include "stdafx.h"
#include <iostream>
#include "Flyweight.h"
#include "Utils.hpp"
#include "Handlers/CreateHandler.h"
#include "Handlers/CreateDefHandler.h"
#include "Handlers/RemoveAllHandler.h"
#include "Handlers/RemoveHandler.h"
#include "Handlers/SetValueHandler.h"
#include "Handlers/GetValueHandler.h"
#include "Handlers/CreateCopyHandler.h"
#include "Handlers/PrintHandler.h"
#include "Handlers/PrintAllHandler.h"
#include "Handlers/HelpHandler.h"

using namespace defaultVals;
using namespace messageLiterals;
using namespace funs;

std::vector<CTable*> CFlyweight::cache_;

ERROR_CODE CFlyweight::interpretCommand(std::vector<std::string>& inCommand)
{
    if(inCommand.size() == ZERO)
    {
        return ERROR_CODE::ERROR;
    }

    ERROR_CODE returnedCode = ERROR_CODE::ERROR;
    std::string command(inCommand[idxOf::COMMAND]);

    if(command == CREATE)
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
    else if(command == ERROR)
    {
        returnedCode = ERROR_CODE::ERROR;
    }
    else
    {
        returnedCode = returnResultCode(ERROR_CODE::ERROR);
    }

    return returnedCode;
}

#pragma region ********** CTORS_DTORS **********

void CFlyweight::createCFlyweight(int inSize)
{
    cache_ = std::vector<CTable*>(inSize);
}

void CFlyweight::releaseResources()
{
    releaseResources(cache_);
}

void CFlyweight::releaseResources(std::vector<CTable*>& inCache)
{
    for(auto i = ZERO; i < inCache.size(); i++)
    {
        delete inCache[i];
    }
    inCache.clear();
}

CFlyweight::CFlyweight()
{
    CFlyweight::createCFlyweight(INITIAL_FLYWEIGHT_CACHE_SIZE);
}

CFlyweight::CFlyweight(std::vector<std::string>& inCommand,
    std::vector<CTable*>& inCache)
{
    CFlyweight::createCFlyweight(inCache);
    CFlyweight::interpretCommand(std::move(inCommand));
}

CFlyweight::~CFlyweight()
{
    CFlyweight::releaseResources();
}

void CFlyweight::createCFlyweight(std::vector<CTable*>& inCache)
{
    cache_ = std::move(inCache);
}

# pragma endregion
