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
using namespace tupleIdx;

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

void repointTable(CShape** sourceTable, CShape** goalTable, int size)
{
    for (int i = 0; i < size; i++)
    {
        goalTable[i] = sourceTable[i];
    }
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
    std::string receivedId(wholeCommand_[idxOf::ID_OF_POINTS]);
    int idxOrAmount = std::stoi(receivedId);
    int cacheSize = std::get<SIZE>(inCache);

    if (idxOrAmount < ZERO)
    {
        return RETURN_CODE::ERROR;
    }
    else
    {
        int newSize = cacheSize + idxOrAmount;
        CShape** newTable = new CShape*[newSize];

        repointTable(
            reinterpret_cast<CShape**>(std::get<ARRAY>(inCache)),
            newTable,
            cacheSize
        );

        int cursor = cacheSize;
        for (int i = 0; i < idxOrAmount; i++, cursor++)
        {
            CFlyweight::updateIsInitializedPointCache(cursor, true);
            newTable[cursor] = CPoint::buildNewObj(DEFAULT_IN_TABLE_SIZE);
        }
        CFlyweight::setPointCacheSize(newSize);
        CFlyweight::updatePointCache(newTable);
    }
    return RETURN_CODE::DONE;
}

RETURN_CODE CGoHandler::performOn(CShapeWithSize inCache)
{
    std::string receivedId(wholeCommand_[idxOf::ID_OF_POINTS]);
    int idxOrAmount = std::stoi(receivedId);
    int cacheSize = std::get<SIZE>(inCache);

    if (idxOrAmount < ZERO)
    {
        return RETURN_CODE::ERROR;
    }
    else
    {
        int newSize = cacheSize + idxOrAmount;
        CShape** newTable = new CShape*[newSize];

        repointTable(
            reinterpret_cast<CShape**>(std::get<ARRAY>(inCache)),
            newTable,
            cacheSize
        );

        int cursor = cacheSize;
        for (int i = 0; i < idxOrAmount; i++, cursor++)
        {
            CFlyweight::updateIsInitializedShapeCache(cursor, true);
            newTable[cursor] = CRectangle::buildNewObj(DEFAULT_IN_TABLE_SIZE);
        }
        CFlyweight::setShapeCacheSize(newSize);
        CFlyweight::updateShapeCache(newTable);
    }
    return RETURN_CODE::DONE;
}

CGoHandler::~CGoHandler()
{

}
