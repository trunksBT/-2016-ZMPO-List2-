#include "stdafx.h"
#include "IShapeHandler.h"
#include <iostream>
#include "../Utils.hpp"
#include "../Logger.h"

using namespace defaultVals;
using namespace funs;

IShapeHandler::IShapeHandler(std::vector<std::string>& inCommand)
{
    wholeCommand_ = inCommand;
    Logger::info() << PRE_PRINT << wholeCommand_[idxOf::COMMAND] << POST_PRINT;
}

ERROR_CODE IShapeHandler::checkCorrectnessAndPerform(std::vector<CShapeWithSize>& inCache)
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

IShapeHandler::~IShapeHandler()
{
    Logger::info() << POST_PRINT;
}
