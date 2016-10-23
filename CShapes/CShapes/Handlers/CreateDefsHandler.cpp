#include "stdafx.h"
#include <iostream>

#include "CreateDefsHandler.h"
#include "../Utils.hpp"
#include "../Point.hpp"
#include "../Flyweight.h"
#include "../UtilsForMT.h"

using namespace defaultVals;
using namespace cacheIdx;
using namespace funs;
using namespace assertWrapper;

CGoHandler::CGoHandler(std::vector<std::string>& inCommand)
    : IHandler(inCommand), IPointHandler(inCommand), IShapeHandler(inCommand), IPointAndRectangleHandler(inCommand)
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

RETURN_CODE CGoHandler::perform(
    CPointWithSize inPointCache,
    CShapeWithSize inRectangleCache)
{
    RETURN_CODE retCode = RETURN_CODE::ERROR;

    retCode = getFinalResultCode
    ({
        perform(inPointCache),
        perform(inRectangleCache),
    });

    return retCode;
}

RETURN_CODE CGoHandler::performOn(
    CPointWithSize inPointCache,
    CShapeWithSize inRectangleCache)
{
    return RETURN_CODE::ERROR;
}

RETURN_CODE CGoHandler::perform(CShapeWithSize inCache)
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

RETURN_CODE CGoHandler::perform(CPointWithSize inCache)
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

RETURN_CODE CGoHandler::performOn(CPointWithSize inCache)
{
    std::string receivedId(wholeCommand_[idxOf::AMOUNT]);
    int idxOrAmount = std::stoi(receivedId);
    int cacheSize = inCache.second;

    if (idxOrAmount < ZERO)
    {
        return RETURN_CODE::ERROR;
    }
    else if (cacheSize < idxOrAmount)
    {
        return RETURN_CODE::ERROR;
    }
    else
    {
        //for (int ammountOfCreatedObj = ZERO; ammountOfCreatedObj < idxOrAmount;)
        //{
        //    if (!CFlyweight::isInitializedPointCache_[ammountOfCreatedObj] || inCache[CTABLE_IDX].first[ammountOfCreatedObj] == nullptr)
        //    {
        //        inCache[CTABLE_IDX].first[ammountOfCreatedObj] = CPoint::buildNewObj();
        //        ammountOfCreatedObj++;
        //    }
        //}
    }

    return RETURN_CODE::DONE;
}

RETURN_CODE CGoHandler::performOn(CShapeWithSize inCache)
{
    std::string receivedId(wholeCommand_[idxOf::ID_OF_SHAPES]);
    int idxOrAmount = std::stoi(receivedId);
    int cacheSize = inCache.second;

    if (idxOrAmount < ZERO)
    {
        return RETURN_CODE::ERROR;
    }
    else if (cacheSize < idxOrAmount)
    {
        return RETURN_CODE::ERROR;
    }
    else
    {
        //for (int ammountOfCreatedObj = ZERO; ammountOfCreatedObj < idxOrAmount;)
        //{
        //    if (!CFlyweight::isInitializedPointCache_[ammountOfCreatedObj] || inCache[CTABLE_IDX].first[ammountOfCreatedObj] == nullptr)
        //    {
        //        inCache[CTABLE_IDX].first[ammountOfCreatedObj] = CPoint::buildNewObj();
        //        ammountOfCreatedObj++;
        //    }
        //}
    }

    return RETURN_CODE::DONE;
}

CGoHandler::~CGoHandler()
{

}
