#include "stdafx.h"
#include <iostream>

#include "PrintHandler.h"
#include "../Utils.hpp"
#include "../Point.hpp"
#include "../Flyweight.h"

//using namespace defaultVals;
//
//using namespace funs;
//
//CPrintHandler::CPrintHandler(std::vector<std::string>& inCommand)
//    : IPointHandler(inCommand)
//{
//}
//
//const int CPrintHandler::getProperAmountOfArgs()
//{
//    return 2;
//}
//
//std::string CPrintHandler::getProperTypesOfArgs()
//{
//    return "si";
//}
//
//RETURN_CODE CPrintHandler::performOn(std::vector<CPointWithSize>& inCache)
//{
//    std::string receivedId(wholeCommand_[idxOf::AMOUNT]);
//    int idxOrAmount = std::stoi(receivedId);
//
//    //if(isProperIdx(idxOrAmount, inCache))
//    //{
//    //    CPoint* retTable = inCache[idxOrAmount].first;
//    //    if(retTable != nullptr)
//    //    {
//    //        std::cout << retTable->toString();
//    //    }
//    //    else
//    //    {
//    //        return returnResultCode(RETURN_CODE::ERROR);
//    //    }
//    //    retTable = nullptr;
//    //}
//    //else
//    //{
//    //    return returnResultCode(RETURN_CODE::ERROR);
//    //}
//
//    return RETURN_CODE::DONE;
//}
