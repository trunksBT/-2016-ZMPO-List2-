#include "stdafx.h"
#include <iostream>

#include "RemoveHandler.h"
#include "../Utils.hpp"
#include "../Point.hpp"
#include "../Flyweight.h"

using namespace defaultVals;

using namespace funs;

CRemoveHandler::CRemoveHandler(std::vector<std::string>& inCommand)
    : IPointHandler(inCommand)
{}

const int CRemoveHandler::getProperAmountOfArgs()
{
    return 2;
}

std::string CRemoveHandler::getProperTypesOfArgs()
{
    return "si";
}

ERROR_CODE CRemoveHandler::performOn(std::vector<CPointWithSize>& inCache)
{
    std::string receivedId(wholeCommand_[idxOf::AMOUNT]);
    int idxOrAmount = std::stoi(receivedId);

    //if (isProperIdx(idxOrAmount, inCache))
    //{
    //    CPoint* retTable = inCache[idxOrAmount].first;
    //    if (retTable != nullptr)
    //    {
    //        std::cout << retTable->getName();
    //    }
    //    delete retTable;
    //    inCache[idxOrAmount].first = nullptr;
    //}
    //else
    //{
    //    return returnResultCode(ERROR_CODE::ERROR);
    //}

    return ERROR_CODE::DONE;
}