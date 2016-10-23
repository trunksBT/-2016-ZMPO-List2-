#include "stdafx.h"
#include <iostream>

#include "RemoveAllHandler.h"
#include "../Utils.hpp"
#include "../CPoint.hpp"
#include "../Flyweight.h"

using namespace defaultVals;

using namespace funs;

CRemoveAllHandler::CRemoveAllHandler(std::vector<std::string>& inCommand)
    : IHandler(inCommand)
{
}

const int CRemoveAllHandler::getProperAmountOfArgs()
{
    return 1;
}

std::string CRemoveAllHandler::getProperTypesOfArgs()
{
    return "s";
}

ERROR_CODE CRemoveAllHandler::performOn(std::vector<CPointWithSize>& inCache)
{
    if(isVectorEmpty(inCache))
    {
        return returnResultCode(ERROR_CODE::ERROR);
    }

    CFlyweight::releaseResources();

    return ERROR_CODE::DONE;
}
