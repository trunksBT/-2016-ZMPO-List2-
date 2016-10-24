#include "stdafx.h"
#include "Utils.hpp"
#include "Point.hpp"
#include <map>
#include <iostream>
#include <string>
#include "Logger.h"

using namespace defaultVals;
using namespace tupleIdx;

namespace funs
{
    bool isMinus(char inChar)
    {
        return inChar == '-';
    }
    
    bool isDot(char inChar)
    {
        return inChar == '.';
    }

    bool isProperIdx(int idxOrAmount, CShapeWithSize inCache)
    {
        return idxOrAmount > MINUS_ONE && idxOrAmount < std::get<SIZE>(inCache);
    }

    bool isProperIdx(int inIdx, int inSize)
    {
        return inIdx > MINUS_ONE && inIdx < inSize;
    }

    std::string toString(CODE inCode)
    {
        static std::map<CODE, std::string> codeToString;

        codeToString[CODE::DONE] = "DONE";
        codeToString[CODE::ERROR] = "ERROR";
        codeToString[CODE::CLOSE] = "CLOSE";
        codeToString[CODE::NOT_INITIALIZED] = "NOT_INITIALIZED";

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

    bool isInt(std::string inChain)
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

    bool isDoubleLimit(std::string inChain)
    {
        bool isLimit = true;

        if (inChain.size() > 5)
        {
            return true;
        }
        else if (inChain.size() < 5)
        {
            return false;
        }

        long inLong = std::stol(inChain);

        if (inLong <= MAX_INT_VAL)
        {
            return true;
        }
        else
        {
            return false;
        }

    }

    bool isDouble(std::string inChain)
    {
        bool isNumber = true;

        if (isIntLimit(inChain))
        {
            return false;
        }
        else if (inChain.size() == ONE && inChain[ZERO] == '-')
        {
            return false;
        }

        for (int i = 0; i < inChain.size() && isNumber; i++)
        {
            if (i == 0 && inChain[i] == '-')
            {
                isNumber &= true;
            }
            else if (isdigit(inChain[i]))
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

    bool isProperTypeOfArgs(std::vector<std::string>& inCommand, std::string inProperTypeOfArgs)
    {
        bool isProperType = true;
        for(int i = 0; i < inCommand.size() && isProperType && i< inProperTypeOfArgs.size(); i++)
        {
            if (inProperTypeOfArgs[i] == DOUBLE_TYPE)
            {
                if (!isDouble(inCommand[i]))
                {
                    isProperType &= true;
                }
            }
            else if(inProperTypeOfArgs[i] == INT_TYPE)
            {
                if (!isInt(inCommand[i]))
                {
                    isProperType &= false;
                }
            }
        }
        return isProperType;
    }

    int toInt(char inChar)
    {
        return inChar - 48;
    }

}
namespace fullCommands
{
    //std::string createArgs =
    //    std::string(messageLiterals::CREATE) +
    //    std::string(defaultVals::SPACE) +
    //    std::string(commandArgs::IDX) +
    //    std::string(defaultVals::SPACE) +
    //    std::string(commandArgs::SIZE) +
    //    std::string(defaultVals::SPACE) +
    //    std::string(commandArgs::NAME);

    //std::string createCopyArgs =
    //    std::string(messageLiterals::CREATE_COPY) +
    //    std::string(defaultVals::SPACE) +
    //    std::string(commandArgs::IDX) +
    //    std::string(defaultVals::SPACE) +
    //    std::string(commandArgs::IDX);

    //std::string getValueArgs =
    //    std::string(messageLiterals::GET_VALUE) +
    //    std::string(defaultVals::SPACE) +
    //    std::string(commandArgs::IDX) +
    //    std::string(defaultVals::SPACE) +
    //    std::string(commandArgs::IDX);

    //std::string setValueArgs =
    //    std::string(messageLiterals::SET_VALUE) +
    //    std::string(defaultVals::SPACE) +
    //    std::string(commandArgs::IDX) +
    //    std::string(defaultVals::SPACE) +
    //    std::string(commandArgs::IDX) +
    //    std::string(defaultVals::SPACE) +
    //    std::string(commandArgs::VALUE);

    //std::string printArgs =
    //    std::string(messageLiterals::PRINT) +
    //    std::string(defaultVals::SPACE) +
    //    std::string(commandArgs::IDX);

    //std::string printAllArgs =
    //    std::string(messageLiterals::PRINT_ALL);

    //std::string deleteArgs =
    //    std::string(messageLiterals::DELETE) +
    //    std::string(defaultVals::SPACE) +
    //    std::string(commandArgs::IDX);

    //std::string deleteAllArgs =
    //    std::string(messageLiterals::REMOVE_ALL);

    //std::string closeArgs =
    //    std::string(messageLiterals::CLOSE);

    //std::string helpArgs =
    //    std::string(messageLiterals::HELP);

    //std::vector<std::string> allCommands =
    //{
    //    createArgs,
    //    createDefArgs,
    //    createCopyArgs,
    //    getValueArgs,
    //    setValueArgs,
    //    printArgs,
    //    printAllArgs,
    //    deleteArgs,
    //    deleteAllArgs,
    //    closeArgs,
    //    helpArgs
    //};
}

