#include "stdafx.h"
#include <iostream>

#include "CreateDefHandler.h"
#include "../Utils.hpp"
#include "../Point.hpp"
#include "../Flyweight.h"

using namespace defaultVals;
using namespace funs;
using namespace cacheIdx;

CCreateDefHandler::CCreateDefHandler(std::vector<std::string>& inCommand)
    : IHandler(inCommand)
{
}

const int CCreateDefHandler::getProperAmountOfArgs()
{
    return 2;
}

std::string CCreateDefHandler::getProperTypesOfArgs()
{
    return "si";
}

ERROR_CODE CCreateDefHandler::performOn(std::vector<CPointWithSize>& inCache)
{
    std::string receivedId(wholeCommand_[idxOf::ID_OF_CTABLE]);

    int idxOrAmount = std::stoi(receivedId);
    if(!isProperIdx(idxOrAmount, inCache[CTABLE_IDX].second))
    {
        return returnResultCode(ERROR_CODE::ERROR);
    }

    //if(inCache[idxOrAmount].first != nullptr)
    //{
    //    delete inCache[idxOrAmount].first;
    //}
    //inCache[idxOrAmount].first = CPoint::buildNewObj();

    return ERROR_CODE::DONE;
}
