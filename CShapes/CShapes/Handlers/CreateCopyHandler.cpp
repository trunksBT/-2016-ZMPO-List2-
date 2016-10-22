#include "stdafx.h"
#include <iostream>

#include "CreateCopyHandler.h"
#include "../Utils.hpp"
#include "../CTable.hpp"
#include "../Flyweight.h"

using namespace defaultVals;

using namespace funs;

CCreateCopyHandler::CCreateCopyHandler(std::vector<std::string>& inCommand)
    : IHandler(inCommand)
{
}

const int CCreateCopyHandler::getProperAmountOfArgs()
{
    return 3;
}

std::string CCreateCopyHandler::getProperTypesOfArgs()
{
    return "sii";
}

ERROR_CODE CCreateCopyHandler::performOn(std::vector<CTable*>& inCache)
{
    std::string receivedDestinyId(wholeCommand_[idxOf::ID_OF_CTABLE]);
    int destinyId = std::stoi(receivedDestinyId);
    std::string receivedSourceId(wholeCommand_[idxOf::GOAL_ID]);
    int sourceId = std::stoi(receivedSourceId);

    if(isProperIdx(sourceId, inCache))
    {
        if(inCache[sourceId] == nullptr)
        {
            return returnResultCode(ERROR_CODE::ERROR);
        }
        else if(destinyId != sourceId)
        {
            CTable* copiedObj = CTable::buildNewObj(*inCache[sourceId]);
            bool isProperDestinyIdx = isProperIdx(destinyId, inCache);
            if(isProperDestinyIdx && inCache[destinyId] == nullptr)
            {
                inCache[destinyId] = copiedObj;
            }
            else if(isProperDestinyIdx && inCache[destinyId] != nullptr)
            {
                delete inCache[destinyId];
                inCache[destinyId] = copiedObj;
            }
            else
            {
                inCache.emplace_back(copiedObj);
            }
        }
        else
        {
            return returnResultCode(ERROR_CODE::ERROR);
        }
    }
    else
    {
        return returnResultCode(ERROR_CODE::ERROR);
    }

    return ERROR_CODE::DONE;
}
