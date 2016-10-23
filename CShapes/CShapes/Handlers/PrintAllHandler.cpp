#include "stdafx.h"
#include <iostream>

#include "PrintAllHandler.h"
#include "../Utils.hpp"
#include "../Point.hpp"
#include "../Flyweight.h"
#include "../UtilsForMT.h"
#include "../Logger.h"

using namespace defaultVals;
using namespace funs;
using namespace assertWrapper;
using namespace tupleIdx;
using namespace typeLiterals;

CPrintAllHandler::CPrintAllHandler(std::vector<std::string>& inCommand)
    : IHandler(inCommand), IPointHandler(inCommand), IShapeHandler(inCommand), IPointAndRectangleHandler(inCommand)
{}

const int CPrintAllHandler::getProperAmountOfArgs()
{
    return 1;
}

std::string CPrintAllHandler::getProperTypesOfArgs()
{
    return "s";
}

RETURN_CODE CPrintAllHandler::perform(
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

RETURN_CODE CPrintAllHandler::performOn(
    CPointWithSize inPointCache,
    CShapeWithSize inRectangleCache)
{
    return RETURN_CODE::ERROR;
}

RETURN_CODE CPrintAllHandler::perform(CShapeWithSize inCache)
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

RETURN_CODE CPrintAllHandler::perform(CPointWithSize inCache)
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

RETURN_CODE CPrintAllHandler::performOn(CPointWithSize inCache)
{
    int cacheSize = std::get<SIZE>(inCache);

    Logger::info() << POINTS << POST_PRINT;

    for (int i = 0; i < cacheSize; i++)
    {
        if (std::get<INITIALIZED_MAP>(inCache)[i])
        {
            Logger::info() << std::get<ARRAY>(inCache)[i]->toString();
        }
        else
        {
            Logger::info() << toString(RETURN_CODE::NOT_INITIALIZED);
        }

        Logger::info() << POST_PRINT;
    }

    return RETURN_CODE::DONE;
}

RETURN_CODE CPrintAllHandler::performOn(CShapeWithSize inCache)
{
    int cacheSize = std::get<SIZE>(inCache);

    Logger::info() << SHAPES << POST_PRINT;

    for (int i = 0; i < cacheSize; i++)
    {
        if (std::get<INITIALIZED_MAP>(inCache)[i])
        {
            Logger::info() << std::get<ARRAY>(inCache)[i]->toString();
        }
        else
        {
            Logger::info() << toString(RETURN_CODE::NOT_INITIALIZED);
        }

        Logger::info() << POST_PRINT;
    }

    return RETURN_CODE::DONE;
}
