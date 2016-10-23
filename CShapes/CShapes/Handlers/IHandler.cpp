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

CODE IHandler::checkTypeAndAmountOfArgs()
{
    if (!isProperAmmountOfArgs(wholeCommand_, getProperAmountOfArgs()))
    {
        return CODE::ERROR;
    }
    else if (!isProperTypeOfArgs(wholeCommand_, getProperTypesOfArgs()))
    {
        return CODE::ERROR;
    }
    else
    {
        return CODE::DONE;
    }
}

IHandler::~IHandler()
{
    Logger::info() << POST_PRINT;
}
