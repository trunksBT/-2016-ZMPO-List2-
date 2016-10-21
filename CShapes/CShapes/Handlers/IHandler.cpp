#include "stdafx.h"
#include "IHandler.h"
#include <iostream>
#include "../Utils.hpp"
#include "../Logger.h"

using namespace defaultVals;
using namespace funs;

IHandler::IHandler(std::vector<std::string>& inCommand)
{
    wholeCommand_ = inCommand;
    Logger::info() << PRE_PRINT << wholeCommand_[idxOf::COMMAND] << POST_PRINT;
}

ERROR_CODE IHandler::checkCorrectnessAndPerform(std::vector<CTable*>& inCache)
{
    if(!isProperAmmountOfArgs(wholeCommand_, getProperAmountOfArgs()))
    {
        return returnResultCode(ERROR_CODE::WRONG_AMOUNT_OF_ARGS);
    }
    else if(!isProperTypeOfArgs(wholeCommand_, getProperTypesOfArgs()))
    {
        return returnResultCode(ERROR_CODE::ERROR_ARGS_PARSING);
    }
    else
    {
        return performOn(inCache);
    }
}

IHandler::~IHandler()
{
    Logger::info() << POST_PRINT;
}
