#include "stdafx.h"
#include <iostream>
//
//#include "SetValueHandler.h"
//#include "../Utils.hpp"
//#include "../Point.hpp"
//#include "../Flyweight.h"
//
//using namespace defaultVals;
//
//using namespace funs;
//
//CSetValueHandler::CSetValueHandler(std::vector<std::string>& inCommand)
//    : IPointHandler(inCommand)
//{
//}
//
//const int CSetValueHandler::getProperAmountOfArgs()
//{
//    return 4;
//}
//
//std::string CSetValueHandler::getProperTypesOfArgs()
//{
//    return "siii";
//}
//
//CODE CSetValueHandler::performOn(std::vector<CPointWithSize>& inCache)
//{
//    std::string receivedId(wholeCommand_[idxOf::AMOUNT]);
//    int idxOrAmount = std::stoi(receivedId);
//    std::string receivedIdOfNewVal(wholeCommand_[idxOf::GOAL_ID]);
//    int idOfNewVal = std::stoi(receivedIdOfNewVal);
//    std::string receivedNewVal(wholeCommand_[idxOf::NEW_VAL]);
//    int newVal = std::stoi(receivedNewVal);
//
//    //if(isProperIdx(idxOrAmount, inCache))
//    //{
//    //    CPoint* retTable = inCache[idxOrAmount].first;
//    //    if(retTable != nullptr)
//    //    {
//    //        if(isProperIdx(idOfNewVal, retTable->getSize()))
//    //        {
//    //            retTable->setVal(idOfNewVal, newVal);
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
