#pragma once

#include <vector>
#include "Point.hpp"
#include "Shape.h"
#include <limits>

enum class RETURN_CODE : int
{
    DONE = 0,
    ERROR = 1
};

namespace defaultVals
{
constexpr const char* CURSOR_SIGN = "! ";
constexpr const char* PRE_PRINT = "   ";
constexpr const char* POST_PRINT = "\n";
constexpr const char* SEPARATOR = ": ";
constexpr const char* BRACKET_OPEN = "( ";
constexpr const char* BRACKET_ERROR = " )";
constexpr const char* LEN = "len";
constexpr const char* VALUES = "values";
constexpr const char* SPACE = " ";
constexpr const char* COMMA_SPACE = ", ";
constexpr const char* DEFAULT_TABLE_NAME = "KORYTKO_TABLE";

constexpr const char* POST_COPIED_NAME = "_copy";
constexpr const char* DTOR_PRE_PRINT = "usuwam: ";
constexpr const char* CTOR_COPY_PRE_PRINT = "kopiuj: ";
constexpr const char* CTOR_DEFAULT_PRE_PRINT = "bezp: ";
constexpr const char* CTOR_DEFAULT_MOVE_PRINT = "przenoszenie: ";
constexpr const char* CTOR_ARG1_PRE_PRINT = "parametr: ";
constexpr const int INITIAL_FLYWEIGHT_CACHE_SIZE = 5;
constexpr const int ZERO = 0;
constexpr const int MINUS_ONE = -1;
constexpr const int ONE = 1;
constexpr const int TWO = 2;
constexpr const int FIVE = 5;
constexpr const int TEN = 10;
constexpr const long MAX_INT_VAL = (std::numeric_limits<int>::max)();
constexpr const char* ERRORED_COMMAND_IDX = "Errored command idx";
constexpr const char INT_TYPE = 'i';
constexpr const char STRING_TYPE = 's';
constexpr const int DEFAULT_TABLE_VAL = -1;

constexpr const int DEFAULT_IN_TABLE_SIZE = FIVE;
constexpr const int DEFAULT_FLYWEIGHT_CACHE_SIZE = FIVE;
}

namespace cacheIdx
{
constexpr const int CTABLE_IDX = 0;
}

using CPointWithSize = std::pair<CPoint**, int>;
using CShapeWithSize = std::pair<CShape**, int>;

namespace funs
{
int toInt(char inChar);
std::string toString(RETURN_CODE inCode);
bool isNumber(std::string inChain);
bool isProperIdx(int inIdx, int inSize);
bool isVectorEmpty(std::vector<CPointWithSize>& inCache);
bool isProperIdx(int idxOrAmount, std::vector<CPointWithSize>& inCache);
bool isProperIdx(int inIdxOrAmount, std::vector<CPointWithSize>& inCache);
bool isProperAmmountOfArgs(std::vector<std::string>& inCommand, int inProperAmountOfArgs);
bool isProperTypeOfArgs(std::vector<std::string>& inCommand, std::string inProperTypeOfArgs);
std::vector<CPointWithSize> toVectorOfPairsOfPoints(CPoint** inCache, int inSize);
std::vector<CShapeWithSize> toVectorOfPairsOfShapes(CShape** inCache, int inSize);
}

namespace idxOf
{
constexpr const int COMMAND = 0;
constexpr const int ID_OF_CTABLE = 1;
constexpr const int AMOUNT = 1;
constexpr const int NEW_NAME = 2;
constexpr const int NEW_SIZE = 2;
constexpr const int GOAL_ID = 2;
constexpr const int NEW_VAL = 3;
constexpr const int INITIAL_NAME = 3;
}

namespace messageLiterals
{
constexpr const char* CREATE = "create";
constexpr const char* CREATE_DEF = "createDef";
constexpr const char* GO = "go";
constexpr const char* CREATE_COPY = "createCopy";
constexpr const char* GET_VALUE = "getValue";
constexpr const char* DELETE = "delete";
constexpr const char* REMOVE_ALL = "deleteAll";
constexpr const char* SET_VALUE = "setValue";
constexpr const char* PRINT = "print";
constexpr const char* PRINT_ALL = "printAll";
constexpr const char* CLOSE = "close";
constexpr const char* HELP = "help";
}

namespace commandArgs
{
constexpr const char* IDX = "<idx>";
constexpr const char* SIZE = "<size>";
constexpr const char* NAME = "<name>";
constexpr const char* VALUE = "<value>";
}

namespace fullCommands
{
extern std::string createArgs;
extern std::string createDefArgs;
extern std::string createCopyArgs;
extern std::string getValueArgs;
extern std::string setValueArgs;
extern std::string printArgs;
extern std::string printAllArgs;
extern std::string deleteArgs;
extern std::string deleteAllArgs;
extern std::string closeArgs;
extern std::string helpArgs;
extern std::vector<std::string> allCommands;
}
