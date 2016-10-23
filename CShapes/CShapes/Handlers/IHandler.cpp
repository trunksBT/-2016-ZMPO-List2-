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

RETURN_CODE IHandler::checkCorrectnessAndPerform()
{
    if (!isProperAmmountOfArgs(wholeCommand_, getProperAmountOfArgs()))
    {
        return RETURN_CODE::ERROR;
    }
    else if (!isProperTypeOfArgs(wholeCommand_, getProperTypesOfArgs()))
    {
        return RETURN_CODE::ERROR;
    }
    else
    {
        return RETURN_CODE::DONE;
    }
}

IHandler::~IHandler()
{
    Logger::info() << POST_PRINT;
}
