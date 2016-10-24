#include "stdafx.h"
#include "Stub.hpp"

namespace stub
{
std::vector<std::string> emptyCommand = {};
std::vector<std::string> noCommand = { "" };

std::vector<std::string> gom1m1 = { "go", "-1", "-1" };
std::vector<std::string> gom10 = { "go", "-1", "0" };
std::vector<std::string> go0m1 = { "go", "0", "-1" };
std::vector<std::string> go00 = { "go", "0", "0" };
std::vector<std::string> go10 = { "go", "1", "0" };
std::vector<std::string> go01 = { "go", "0", "1" };
std::vector<std::string> go66 = { "go", "6", "6" };
std::vector<std::string> go60 = { "go", "6", "0" };
std::vector<std::string> go06 = { "go", "0", "6" };

std::vector<std::string> createPoint1_1y5_5y5 = { "createPoint", "1", "1.5", "5.5" };
std::vector<std::string> createPoint6_1y5_5y5 = { "createPoint", "6", "1.5", "5.5" };
std::vector<std::string> createPoint0_m1y5_5y5 = { "createPoint", "0", "-1.5", "5.5" };
std::vector<std::string> createPoint0_1y5_m5y5 = { "createPoint", "0", "1.5", "-5.5" };

std::vector<std::string> setPoint1_1y5_5y5 = { "setPoint", "1", "1.5", "5.5" };
std::vector<std::string> setPoint6_1y5_5y5 = { "setPoint", "6", "1.5", "5.5" };
std::vector<std::string> setPoint0_m1y5_5y5 = { "setPoint", "0", "-1.5", "5.5" };
std::vector<std::string> setPoint0_1y5_m5y5 = { "setPoint", "0", "1.5", "-5.5" };

std::vector<std::string> createDefm1 = { "createDef", "-1" };
std::vector<std::string> createDef0 = { "createDef", "0" };
std::vector<std::string> createDef6 = { "createDef", "6" };

std::vector<std::string> createCopy00 = { "createCopy", "0", "0" };
std::vector<std::string> createCopym1_0 = { "createCopy", "-1", "0" };
std::vector<std::string> createCopym1_m1 = { "createCopy", "-1", "-1" };
std::vector<std::string> createCopy10 = { "createCopy", "1", "0" };
std::vector<std::string> createCopy60 = { "createCopy", "6", "0" };

std::vector<std::string> print0 = { "print", "0" };
std::vector<std::string> printm1 = { "print", "-1" };
std::vector<std::string> print6 = { "print", "6" };
std::vector<std::string> print10 = { "print", "10" };
std::vector<std::string> printAll = { "printAll" };

std::vector<std::string> deletem1 = { "delete", "-1" };
std::vector<std::string> delete0 = { "delete", "0" };
std::vector<std::string> delete10 = { "delete", "10" };
std::vector<std::string> deleteAll = { "deleteAll" };

std::vector<std::string> getValue0_1 = { "getValue", "0", "1" };
std::vector<std::string> getValue1_0 = { "getValue", "1", "0" };
std::vector<std::string> getValuem1_1 = { "getValue", "-1", "1" };
std::vector<std::string> getValue0_m1 = { "getValue", "0", "-1" };
std::vector<std::string> getValue1_2 = { "getValue", "1", "2" };
std::vector<std::string> getValue6_3 = { "getValue", "6", "3" };
std::vector<std::string> getValue10_4 = { "getValue", "10", "4" };
std::vector<std::string> getValue10_10 = { "getValue", "10", "10" };

std::vector<std::string> help = { "help" };
}

namespace wrongAmountStub
{
std::vector<std::string> goToSmall = { "go" };
std::vector<std::string> createToSmall = { "create", "1" };
std::vector<std::string> createDefToSmall = { "createDef" };
std::vector<std::string> createCopy0ToSmall = { "createCopy", "0" };
std::vector<std::string> printToSmall = { "print" };
std::vector<std::string> deleteToSmall = { "delete" };
std::vector<std::string> getValue0ToSmall = { "getValue", "0" };
std::vector<std::string> setValue0_0ToSmall = { "setValue", "0", "0" };
std::vector<std::string> wrongCommandToSmall = { "wrongCommand" };

std::vector<std::string> goToBig = { "go", "0", "6" };
std::vector<std::string> createToBig = { "create", "1", "5", "Name" , "23" };
std::vector<std::string> createDefToBig = { "createDef", "0", "6" };
std::vector<std::string> createCopy0ToBig = { "createCopy", "0", "1", "6" };
std::vector<std::string> printToBig = { "print", "0", "6" };
std::vector<std::string> deleteToBig = { "delete", "0", "6" };
std::vector<std::string> deleteAllToBig = { "deleteAll", "0", "6" };
std::vector<std::string> getValue0ToBig = { "getValue", "0", "0", "6" };
std::vector<std::string> setValue0_0ToBig = { "setValue", "0", "0", "0", "6" };
std::vector<std::string> wrongCommandToBig = { "wrongCommand", "0", "6" };
}

namespace wrongTypeStub
{
std::vector<std::string> goZ = { "go", "Z" };
std::vector<std::string> createZZZ = { "create", "Z", "Z", "Z" };
std::vector<std::string> createDefZ = { "createDef", "Z" };
std::vector<std::string> createCopyZZ = { "createCopy", "Z", "Z" };
std::vector<std::string> printZ = { "print", "Z" };
std::vector<std::string> deleteZ = { "delete", "Z" };
std::vector<std::string> getValueZZ = { "getValue", "Z", "Z" };
std::vector<std::string> setValue0ZZZ = { "setValue", "Z", "Z", "Z" };
std::vector<std::string> setSizeZZ = { "setSize", "Z", "Z" };
}