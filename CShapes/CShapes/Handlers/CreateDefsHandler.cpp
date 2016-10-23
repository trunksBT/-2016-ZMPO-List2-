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
    std::vector<CPointWithSize>& inPointCache,
    std::vector<CShapeWithSize>& inRectangleCache)
{
    RETURN_CODE retCode = RETURN_CODE::ERROR;

    retCode = getFinalResultCode
    ({
        perform(inPointCache),
        perform(inRectangleCache),
    });

    return RETURN_CODE::ERROR;
}

RETURN_CODE CGoHandler::performOn(
    std::vector<CPointWithSize>& inPointCache,
    std::vector<CShapeWithSize>& inRectangleCache)
{
    return RETURN_CODE::ERROR;
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
    int cacheSize = inCache[CTABLE_IDX].second;

    if (idxOrAmount <= ZERO)
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

RETURN_CODE CGoHandler::performOn(std::vector<CShapeWithSize>& inCache)
{
    std::string receivedId(wholeCommand_[idxOf::AMOUNT]);
    int idxOrAmount = std::stoi(receivedId);
    int cacheSize = inCache[CTABLE_IDX].second;

    if (idxOrAmount <= ZERO)
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
