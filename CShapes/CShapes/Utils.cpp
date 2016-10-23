#include "stdafx.h"
#include "Utils.hpp"
#include "CPoint.hpp"
#include <map>
#include <iostream>
#include <string>
#include "Logger.h"

using namespace defaultVals;

namespace funs
{
    bool isProperIdx(int idxOrAmount, std::vector<CPointWithSize>& inCache)
    {
        return idxOrAmount > MINUS_ONE && idxOrAmount < inCache.size();
    }

    bool isProperIdx(int inIdx, int inSize)
    {
        return inIdx > MINUS_ONE && inIdx < inSize;
    }

    std::string toString(ERROR_CODE inCode)
    {
        static std::map<ERROR_CODE, std::string> codeToString;

        codeToString[ERROR_CODE::DONE] = "DONE";
        codeToString[ERROR_CODE::ERROR]= "ERROR";

        return codeToString[inCode];
    }

    bool isProperAmmountOfArgs(std::vector<std::string>& inCommand, int inProperAmountOfArgs)
    {
        return inCommand.size() >= inProperAmountOfArgs;
    }

    bool isIntLimit(std::string inChain)
    {
        bool isLimit = true;

        if(inChain.size() > 5)
        {
            return true;
        }
        else if(inChain.size() < 5)
        {
            return false;
        }

        long inLong = std::stol(inChain);

        if(inLong <= MAX_INT_VAL)
        {
            return true;
        }
        else
        {
            return false;
        }

    }

    bool isNumber(std::string inChain)
    {
        bool isNumber = true;

        if(isIntLimit(inChain))
        {
            return false;
        }
        else if(inChain.size() == ONE && inChain[ZERO] == '-')
        {
            return false;
        }

        for(int i = 0; i < inChain.size() && isNumber; i++)
        {
            if(i == 0 && inChain[i] == '-')
            {
                isNumber &= true;
            }
            else if(isdigit(inChain[i]))
            {
                isNumber &= true;
            }
            else
            {
                isNumber &= false;
            }
        }

        return isNumber;
    }

    ERROR_CODE returnResultCode(ERROR_CODE inResultCode)
    {
        ERROR_CODE resultCode = inResultCode;
        Logger::info() << toString(resultCode);
        return resultCode;
    }

    bool isProperTypeOfArgs(std::vector<std::string>& inCommand, std::string inProperTypeOfArgs)
    {
        bool isProperType = true;
        for(int i = 0; i < inCommand.size() && isProperType && i< inProperTypeOfArgs.size(); i++)
        {
            if(inProperTypeOfArgs[i] == INT_TYPE && !isNumber(inCommand[i]))
            {
                isProperType &= false;
            }
        }
        return isProperType;
    }

    std::vector<CPointWithSize> toVectorOfPairs(CPoint** inCache, int inSize)
    {
        std::vector<CPointWithSize> retVal;
        retVal.push_back({ inCache, inSize });
        return retVal;
    }

    bool isVectorEmpty(std::vector<CPointWithSize>& inCache)
    {
        bool isEmpty = true;
        for(int i = 0; i < inCache.size(); i++)
        {
            isEmpty = inCache[i].first == nullptr;
        }
        return isEmpty;
    }

    int toInt(char inChar)
    {
        return inChar - 48;
    }

}
namespace fullCommands
{
    std::string createArgs =
        std::string(messageLiterals::CREATE) +
        std::string(defaultVals::SPACE) +
        std::string(commandArgs::IDX) +
        std::string(defaultVals::SPACE) +
        std::string(commandArgs::SIZE) +
        std::string(defaultVals::SPACE) +
        std::string(commandArgs::NAME);

    std::string createDefArgs =
        std::string(messageLiterals::CREATE_DEF) +
        std::string(defaultVals::SPACE) +
        std::string(commandArgs::IDX);

    std::string createCopyArgs =
        std::string(messageLiterals::CREATE_COPY) +
        std::string(defaultVals::SPACE) +
        std::string(commandArgs::IDX) +
        std::string(defaultVals::SPACE) +
        std::string(commandArgs::IDX);

    std::string getValueArgs =
        std::string(messageLiterals::GET_VALUE) +
        std::string(defaultVals::SPACE) +
        std::string(commandArgs::IDX) +
        std::string(defaultVals::SPACE) +
        std::string(commandArgs::IDX);

    std::string setValueArgs =
        std::string(messageLiterals::SET_VALUE) +
        std::string(defaultVals::SPACE) +
        std::string(commandArgs::IDX) +
        std::string(defaultVals::SPACE) +
        std::string(commandArgs::IDX) +
        std::string(defaultVals::SPACE) +
        std::string(commandArgs::VALUE);

    std::string printArgs =
        std::string(messageLiterals::PRINT) +
        std::string(defaultVals::SPACE) +
        std::string(commandArgs::IDX);

    std::string printAllArgs =
        std::string(messageLiterals::PRINT_ALL);

    std::string deleteArgs =
        std::string(messageLiterals::DELETE) +
        std::string(defaultVals::SPACE) +
        std::string(commandArgs::IDX);

    std::string deleteAllArgs =
        std::string(messageLiterals::REMOVE_ALL);

    std::string closeArgs =
        std::string(messageLiterals::CLOSE);

    std::string helpArgs =
        std::string(messageLiterals::HELP);

    std::vector<std::string> allCommands =
    {
        createArgs,
        createDefArgs,
        createCopyArgs,
        getValueArgs,
        setValueArgs,
        printArgs,
        printAllArgs,
        deleteArgs,
        deleteAllArgs,
        closeArgs,
        helpArgs
    };
}

