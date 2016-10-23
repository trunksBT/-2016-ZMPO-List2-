#include "stdafx.h"
#include <iostream>

//#include "CreateHandler.h"
//#include "../Utils.hpp"
//#include "../Point.hpp"
//#include "../Flyweight.h"
//
//using namespace defaultVals;
//
//using namespace funs;
//
//CCreateHandler::CCreateHandler(std::vector<std::string>& inCommand)
//    : IPointHandler(inCommand)
//{}
//
//const int CCreateHandler::getProperAmountOfArgs()
//{
//    return 4;
//}
//
//std::string CCreateHandler::getProperTypesOfArgs()
//{
//    return "siis";
//}
//
//RETURN_CODE CCreateHandler::performOn(std::vector<CPointWithSize>& inCache)
//{
//    std::string receivedId(wholeCommand_[idxOf::ID_OF_CTABLE]);
//    int idxOrAmount = std::stoi(receivedId);
//    std::string receivedNewSize(wholeCommand_[idxOf::NEW_SIZE]);
//    int newSize = std::stoi(receivedNewSize);
//    std::string initialName(wholeCommand_[idxOf::INITIAL_NAME]);
//
//    //if(idxOrAmount < 0)
//    //{
//    //    return returnResultCode(RETURN_CODE::ERROR);
//    //}
//    //else
//    //{
//    //    if(newSize > 0)
//    //    {
//    //        if(idxOrAmount > inCache.size())
//    //        {
//    //            inCache.resize(idxOrAmount + ONE);
//    //        }
//    //        if(inCache[idxOrAmount].first != nullptr)
//    //        {
//    //            delete inCache[idxOrAmount].first;
//    //        }
//    //        inCache[idxOrAmount].first = CPoint::buildNewObj(newSize, initialName);
//    //    }
//    //    else
//    //    {
//    //        return returnResultCode(RETURN_CODE::ERROR);
//    //    }
//    //}
//
//    return RETURN_CODE::DONE;
//}
