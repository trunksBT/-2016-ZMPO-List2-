#include "stdafx.h"
#include "IPointHandler.h"
#include <iostream>
#include "../Utils.hpp"
#include "../Logger.h"

using namespace defaultVals;
using namespace funs;

IPointHandler::IPointHandler(std::vector<std::string>& inCommand)
{
    wholeCommand_ = inCommand;
    Logger::info() << PRE_PRINT << wholeCommand_[idxOf::COMMAND] << POST_PRINT;
}

ERROR_CODE IPointHandler::checkCorrectnessAndPerform(std::vector<CPointWithSize>& inCache)
{
    if(!isProperAmmountOfArgs(wholeCommand_, getProperAmountOfArgs()))
    {
        return returnResultCode(ERROR_CODE::ERROR);
    }
    else if(!isProperTypeOfArgs(wholeCommand_, getProperTypesOfArgs()))
    {
        return returnResultCode(ERROR_CODE::ERROR);
    }
    else
    {
        return performOn(inCache);
    }
}

IPointHandler::~IPointHandler()
{
    Logger::info() << POST_PRINT;
}
