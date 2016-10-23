#include "stdafx.h"
#include <iostream>

#include "CreateDefsHandler.h"
#include "../Utils.hpp"
#include "../Point.hpp"
#include "../Flyweight.h"

using namespace defaultVals;
using namespace cacheIdx;
using namespace funs;

CGoHandler::CGoHandler(std::vector<std::string>& inCommand)
    : IHandler(inCommand), IPointHandler(inCommand), IShapeHandler(inCommand)
{
}

const int CGoHandler::getProperAmountOfArgs()
{
    return 3;
}

std::string CGoHandler::getProperTypesOfArgs()
{
    return "sii";
}

RETURN_CODE CGoHandler::perform(std::vector<CShapeWithSize>& inCache)
{
    if (checkCorrectnessAndPerform() == RETURN_CODE::DONE)
    {
        return performOn(inCache);
    }
    else
    {
        return RETURN_CODE::ERROR;
    }
}

RETURN_CODE CGoHandler::perform(std::vector<CPointWithSize>& inCache)
{
    if (checkCorrectnessAndPerform() == RETURN_CODE::DONE)
    {
        return performOn(inCache);
    }
    else
    {
        return RETURN_CODE::ERROR;
    }
}

RETURN_CODE CGoHandler::performOn(std::vector<CPointWithSize>& inCache)
{
    std::string receivedId(wholeCommand_[idxOf::AMOUNT]);
    int idxOrAmount = std::stoi(receivedId);

    if (idxOrAmount <= ZERO)
    {
        return RETURN_CODE::ERROR;
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

    return RETURN_CODE::DONE;
}

RETURN_CODE CGoHandler::performOn(std::vector<CShapeWithSize>& inCache)
{
    std::string receivedId(wholeCommand_[idxOf::AMOUNT]);
    int idxOrAmount = std::stoi(receivedId);

    //if (idxOrAmount <= ZERO)
    //{
    //    return returnResultCode(RETURN_CODE::ERROR);
    //}
    //else
    //{
    //    /* Here will be optional increasing size of Table
    //    if (idxOrAmount > inCache[CTABLE_IDX].second)
    //    {
    //    inCache.reserve(idxOrAmount);
    //    }
    //    */
    //    int cacheSize = inCache[CTABLE_IDX].second;
    //    int cursorIdx = ZERO;
    //    for (int ammountOfCreatedObj = ZERO; ammountOfCreatedObj < idxOrAmount && cursorIdx < cacheSize;)
    //    {
    //        if (cursorIdx < cacheSize)
    //        {
    //            if (!CFlyweight::isInitializedPointCache_[cursorIdx] || inCache[CTABLE_IDX].first[cursorIdx] == nullptr)
    //            {
    //                inCache[CTABLE_IDX].first[cursorIdx] = CPoint::buildNewObj();
    //                ammountOfCreatedObj++;
    //            }
    //        }
    //        /* Here will be optional increasing size of Table
    //        else
    //        {
    //        inCache.emplace_back(CPoint::buildNewObj());
    //        ammountOfCreatedObj++;
    //        }
    //        */
    //        cursorIdx++;
    //    }
    //}

    return RETURN_CODE::DONE;
}

CGoHandler::~CGoHandler()
{

}
