#include "stdafx.h"
#include <iostream>

//#include "GetValueHandler.h"
//#include "../Utils.hpp"
//#include "../Point.hpp"
//#include "../Flyweight.h"
//
//using namespace defaultVals;
//
//using namespace funs;
//
//CGetValueHandler::CGetValueHandler(std::vector<std::string>& inCommand)
//    : IPointHandler(inCommand)
//{}
//
//const int CGetValueHandler::getProperAmountOfArgs()
//{
//    return 3;
//}
//
//std::string CGetValueHandler::getProperTypesOfArgs()
//{
//    return "sii";
//}
//
//CODE CGetValueHandler::purePerform(std::vector<CPointWithSize>& inCache)
//{
//    std::string receivedId(wholeCommand_[idxOf::AMOUNT]);
//    int idxOrAmount = std::stoi(receivedId);
//    std::string receivedIdOfNewVal(wholeCommand_[idxOf::GOAL_ID]);
//    int idOfNewVal = std::stoi(receivedIdOfNewVal);
//
//    //if(isProperIdx(idxOrAmount, inCache))
//    //{
//    //    CPoint* retTable = inCache[idxOrAmount].first;
//    //    if(retTable != nullptr)
//    //    {
//    //        if(isProperIdx(idOfNewVal, retTable->getSize()))
//    //        {
//    //            std::cout << retTable->getVal(idOfNewVal);
//    //        }
//    //        else
//    //        {
//    //            return returnResultCode(CODE::ERROR);
//    //        }
//    //    }
//    //    else
//    //    {
//    //        return returnResultCode(CODE::ERROR);
//    //    }
//    //    retTable = nullptr;
//    //}
//    //else
//    //{
//    //    return returnResultCode(CODE::ERROR);
//    //}
//
//    return CODE::DONE;
//}
