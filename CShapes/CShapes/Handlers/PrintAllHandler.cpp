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

CODE CPrintAllHandler::perform(
    CPointWithSize inPointCache,
    CShapeWithSize inRectangleCache)
{
    if (checkCorrectnessAndPerform() == CODE::DONE)
    {
        return performOn(inPointCache, inRectangleCache);
    }
    else
    {
        return CODE::ERROR;
    }
}

CODE CPrintAllHandler::performOn(
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

CODE CPrintAllHandler::perform(CShapeWithSize inCache)
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

CODE CPrintAllHandler::perform(CPointWithSize inCache)
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

CODE CPrintAllHandler::performOn(CPointWithSize inCache)
{
    int cacheSize = std::get<SIZE>(inCache);
    std::cout << cacheSize << std::endl;

    Logger::info() << POINTS << POST_PRINT;

    for (int i = 0; i < cacheSize; i++)
    {
        if (std::get<INITIALIZED_MAP>(inCache)[i])
        {
            Logger::info() << std::get<ARRAY>(inCache)[i]->toString();
        }
        else
        {
            Logger::info() << toString(CODE::NOT_INITIALIZED);
        }

        Logger::info() << POST_PRINT;
    }

    return CODE::DONE;
}

CODE CPrintAllHandler::performOn(CShapeWithSize inCache)
{
    int cacheSize = std::get<SIZE>(inCache);
    std::cout << cacheSize << std::endl;

    Logger::info() << SHAPES << POST_PRINT;

    for (int i = 0; i < cacheSize; i++)
    {
        if (std::get<INITIALIZED_MAP>(inCache)[i])
        {
            Logger::info() << std::get<ARRAY>(inCache)[i]->toString();
        }
        else
        {
            Logger::info() << toString(CODE::NOT_INITIALIZED);
        }

        Logger::info() << POST_PRINT;
    }

    return CODE::DONE;
}
