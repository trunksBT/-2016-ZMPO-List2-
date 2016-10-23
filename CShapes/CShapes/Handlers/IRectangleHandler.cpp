#include "stdafx.h"
#include "IRectangleHandler.h"
#include <iostream>
#include "../Utils.hpp"
#include "../Logger.h"

using namespace defaultVals;
using namespace funs;

IRectangleHandler::IRectangleHandler(std::vector<std::string>& inCommand)
{
    wholeCommand_ = inCommand;
    Logger::info() << PRE_PRINT << wholeCommand_[idxOf::COMMAND] << POST_PRINT;
}

ERROR_CODE IRectangleHandler::checkCorrectnessAndPerform(std::vector<CPointWithSize>& inCache)
{
    if (!isProperAmmountOfArgs(wholeCommand_, getProperAmountOfArgs()))
    {
        return returnResultCode(ERROR_CODE::ERROR);
    }
    else if (!isProperTypeOfArgs(wholeCommand_, getProperTypesOfArgs()))
    {
        return returnResultCode(ERROR_CODE::ERROR);
    }
    else
    {
        return performOn(inCache);
    }
}

IRectangleHandler::~IRectangleHandler()
{
    Logger::info() << POST_PRINT;
}
