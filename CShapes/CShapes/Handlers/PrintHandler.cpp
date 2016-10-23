#include "stdafx.h"
#include <iostream>

#include "PrintHandler.h"
#include "../Utils.hpp"
#include "../CTable.hpp"
#include "../Flyweight.h"

using namespace defaultVals;

using namespace funs;

CPrintHandler::CPrintHandler(std::vector<std::string>& inCommand)
    : IHandler(inCommand)
{
}

const int CPrintHandler::getProperAmountOfArgs()
{
    return 2;
}

std::string CPrintHandler::getProperTypesOfArgs()
{
    return "si";
}

ERROR_CODE CPrintHandler::performOn(std::vector<CTableWithSize>& inCache)
{
    std::string receivedId(wholeCommand_[idxOf::AMOUNT]);
    int idxOrAmount = std::stoi(receivedId);

    //if(isProperIdx(idxOrAmount, inCache))
    //{
    //    CTable* retTable = inCache[idxOrAmount].first;
    //    if(retTable != nullptr)
    //    {
    //        std::cout << retTable->toString();
    //    }
    //    else
    //    {
    //        return returnResultCode(ERROR_CODE::ERROR);
    //    }
    //    retTable = nullptr;
    //}
    //else
    //{
    //    return returnResultCode(ERROR_CODE::ERROR);
    //}

    return ERROR_CODE::DONE;
}
