#include "stdafx.h"
#include <iostream>

#include "CreateDefsHandler.h"
#include "../Utils.hpp"
#include "../CPoint.hpp"
#include "../Flyweight.h"

using namespace defaultVals;
using namespace cacheIdx;
using namespace funs;

CCreateDefsHandler::CCreateDefsHandler(std::vector<std::string>& inCommand)
    : IHandler(inCommand)
{}

const int CCreateDefsHandler::getProperAmountOfArgs()
{
    return 2;
}

std::string CCreateDefsHandler::getProperTypesOfArgs()
{
    return "si";
}

ERROR_CODE CCreateDefsHandler::performOn(std::vector<CPointWithSize>& inCache)
{
    std::string receivedId(wholeCommand_[idxOf::AMOUNT]);
    int idxOrAmount = std::stoi(receivedId);

    if (idxOrAmount <= ZERO)
    {
        return returnResultCode(ERROR_CODE::ERROR);
    }
    else
    {
        /* Here will be optional increasing size of Table
        if (idxOrAmount > inCache[CTABLE_IDX].second)
        {
            inCache.reserve(idxOrAmount);
        }
        */
        int cacheSize = inCache[CTABLE_IDX].second;
        int cursorIdx = ZERO;
        for (int ammountOfCreatedObj = ZERO; ammountOfCreatedObj < idxOrAmount && cursorIdx < cacheSize;)
        {
            if (cursorIdx < cacheSize)
            {
                if (!CFlyweight::isInitializedPointCache_[cursorIdx] || inCache[CTABLE_IDX].first[cursorIdx] == nullptr)
                {
                    inCache[CTABLE_IDX].first[cursorIdx] = CPoint::buildNewObj();
                    ammountOfCreatedObj++;
                }
            }
            /* Here will be optional increasing size of Table 
            else
            {
                inCache.emplace_back(CPoint::buildNewObj());
                ammountOfCreatedObj++;
            }
            */
            cursorIdx++;
        }
    }

    return ERROR_CODE::DONE;
}