#include "stdafx.h"
#include <iostream>
//
//#include "CreateCopyHandler.h"
//#include "../Utils.hpp"
//#include "../Point.hpp"
//#include "../Flyweight.h"
//
//using namespace defaultVals;
//
//using namespace funs;
//
//CCreateCopyHandler::CCreateCopyHandler(std::vector<std::string>& inCommand)
//    : IPointHandler(inCommand)
//{
//}
//
//const int CCreateCopyHandler::getProperAmountOfArgs()
//{
//    return 3;
//}
//
//std::string CCreateCopyHandler::getProperTypesOfArgs()
//{
//    return "sii";
//}
//
//RETURN_CODE CCreateCopyHandler::performOn(std::vector<CPointWithSize>& inCache)
//{
//    std::string receivedDestinyId(wholeCommand_[idxOf::ID_OF_CTABLE]);
//    int destinyId = std::stoi(receivedDestinyId);
//    std::string receivedSourceId(wholeCommand_[idxOf::GOAL_ID]);
//    int sourceId = std::stoi(receivedSourceId);
//
//    //if(isProperIdx(sourceId, inCache))
//    //{
//    //    if(inCache[sourceId].first == nullptr)
//    //    {
//    //        return returnResultCode(RETURN_CODE::ERROR);
//    //    }
//    //    else if(destinyId != sourceId)
//    //    {
//    //        CPoint* copiedObj = CPoint::buildNewObj(*inCache[sourceId].first);
//    //        bool isProperDestinyIdx = isProperIdx(destinyId, inCache);
//    //        if(isProperDestinyIdx && inCache[destinyId].first == nullptr)
//    //        {
//    //            inCache[destinyId].first = copiedObj;
//    //        }
//    //        else if(isProperDestinyIdx && inCache[destinyId].first != nullptr)
//    //        {
//    //            delete inCache[destinyId].first;
//    //            inCache[destinyId].first = copiedObj;
//    //        }
//    //        else
//    //        {
//    //            inCache.emplace_back(copiedObj);
//    //        }
//    //    }
//    //    else
//    //    {
//    //        return returnResultCode(RETURN_CODE::ERROR);
//    //    }
//    //}
//    //else
//    //{
//    //    return returnResultCode(RETURN_CODE::ERROR);
//    //}
//
//    return RETURN_CODE::DONE;
//}
