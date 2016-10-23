#include "stdafx.h"
#include <iostream>

//#include "RemoveAllHandler.h"
//#include "../Utils.hpp"
//#include "../Point.hpp"
//#include "../Flyweight.h"
//
//using namespace defaultVals;
//
//using namespace funs;
//
//CRemoveAllHandler::CRemoveAllHandler(std::vector<std::string>& inCommand)
//    : IPointHandler(inCommand)
//{
//}
//
//const int CRemoveAllHandler::getProperAmountOfArgs()
//{
//    return 1;
//}
//
//std::string CRemoveAllHandler::getProperTypesOfArgs()
//{
//    return "s";
//}
//
//RETURN_CODE CRemoveAllHandler::performOn(std::vector<CPointWithSize>& inCache)
//{
//    if(isVectorEmpty(inCache))
//    {
//        return returnResultCode(RETURN_CODE::ERROR);
//    }
//
//    CFlyweight::releaseResources();
//
//    return RETURN_CODE::DONE;
//}
