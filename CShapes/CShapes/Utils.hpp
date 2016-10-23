#pragma once

#include <vector>
#include "Point.hpp"
#include "Shape.h"
#include <limits>
#include <tuple>
#include <map>

enum class RETURN_CODE : int
{
    DONE = 0,
    ERROR = 1,
    CLOSE = 10
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
constexpr const int POINTS_IDX = 0;
constexpr const int SHAPES_IDX = 1;
}

namespace tupleIdx
{
constexpr const int ARRAY = 0;
constexpr const int SIZE = 1;
constexpr const int INITIALIZED_MAP = 2;
}

using CShapeWithSize = std::tuple<CShape**, int, std::map<int, bool>>;
using CPointWithSize = std::tuple<CPoint**, int, std::map<int, bool>>;

namespace funs
{
int toInt(char inChar);
std::string toString(RETURN_CODE inCode);
bool isNumber(std::string inChain);
bool isProperIdx(int inIdx, int inSize);
bool isProperIdx(int idxOrAmount, CShapeWithSize inCache);
bool isProperAmmountOfArgs(std::vector<std::string>& inCommand, int inProperAmountOfArgs);
bool isProperTypeOfArgs(std::vector<std::string>& inCommand, std::string inProperTypeOfArgs);
}

namespace idxOf
{
constexpr const int COMMAND = 0;
constexpr const int ID_OF_POINTS = 1;
constexpr const int ID_OF_SHAPES = 2;
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
