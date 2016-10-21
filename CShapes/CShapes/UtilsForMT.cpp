#include "stdafx.h"
#include "UtilsForMT.h"

#include <gtest/gtest.h>
#include "Utils.hpp"
#include "Logger.h"

using namespace defaultVals;
using namespace funs;

namespace assertWrapper
{
ResultCode getFinalResultCode(std::vector<ERROR_CODE> inCodes)
{
    bool isLegit = true;
    ERROR_CODE resultCode = ERROR_CODE::INITIAL_VAL;
    int idxOfWrongCode = MINUS_ONE;

    for(int i = 0; i < inCodes.size() && isLegit; i++)
    {
        if(inCodes[i] == ERROR_CODE::SEEMS_LEGIT)
        {
            isLegit &= true;
            resultCode = ERROR_CODE::SEEMS_LEGIT;
        }
        else
        {
            isLegit &= false;
            resultCode = inCodes[i];
            idxOfWrongCode = i;
        }
    }

    return std::move(std::make_pair(idxOfWrongCode, resultCode));
}

}