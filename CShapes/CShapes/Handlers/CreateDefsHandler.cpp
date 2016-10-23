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

CODE CGoHandler::perform(
    CPointWithSize inPointCache,
    CShapeWithSize inRectangleCache)
{
    CODE retCode = CODE::ERROR;

    retCode = getFinalResultCode
    ({
        perform(inPointCache),
        perform(inRectangleCache),
    });

    return retCode;
}

CODE CGoHandler::performOn(
    CPointWithSize inPointCache,
    CShapeWithSize inRectangleCache)
{
    return CODE::ERROR;
}

CODE CGoHandler::perform(CShapeWithSize inCache)
{
    if (checkCorrectnessAndPerform() == CODE::DONE)
    {
        return performOn(inCache);
    }
    else
    {
        return CODE::ERROR;
    }
}

CODE CGoHandler::perform(CPointWithSize inCache)
{
    if (checkCorrectnessAndPerform() == CODE::DONE)
    {
        return performOn(inCache);
    }
    else
    {
        return CODE::ERROR;
    }
}

CODE CGoHandler::performOn(CPointWithSize inCache)
{
    std::string receivedId(wholeCommand_[idxOf::ID_OF_POINTS]);
    int idxOrAmount = std::stoi(receivedId);
    int cacheSize = std::get<SIZE>(inCache);

    if (idxOrAmount < ZERO)
    {
        return CODE::ERROR;
    }
    else
    {
        if (idxOrAmount == ZERO)
        {
            return CODE::DONE;
        }
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
        newTable = nullptr;
    }
    return CODE::DONE;
}

CODE CGoHandler::performOn(CShapeWithSize inCache)
{
    std::string receivedId(wholeCommand_[idxOf::ID_OF_SHAPES]);
    int idxOrAmount = std::stoi(receivedId);
    int cacheSize = std::get<SIZE>(inCache);

    if (idxOrAmount < ZERO)
    {
        return CODE::ERROR;
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
        newTable = nullptr;
    }
    return CODE::DONE;
}

CGoHandler::~CGoHandler()
{

}
