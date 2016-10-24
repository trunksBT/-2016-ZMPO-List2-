#pragma once

#include <vector>
#include <string>

namespace stub
{
extern std::vector<std::string> emptyCommand;
extern std::vector<std::string> noCommand;

extern std::vector<std::string> gom1m1;
extern std::vector<std::string> gom10;
extern std::vector<std::string> go0m1;
extern std::vector<std::string> go00;
extern std::vector<std::string> go10;
extern std::vector<std::string> go01;
extern std::vector<std::string> go66;
extern std::vector<std::string> go60;
extern std::vector<std::string> go06;

extern std::vector<std::string> createPoint1_1y5_5y5;
extern std::vector<std::string> createPoint6_1y5_5y5;
extern std::vector<std::string> createPoint0_m1y5_5y5;
extern std::vector<std::string> createPoint0_1y5_m5y5;

extern std::vector<std::string> createDefm1;
extern std::vector<std::string> createDef0;
extern std::vector<std::string> createDef6;
extern std::vector<std::string> createCopy00;
extern std::vector<std::string> createCopym1_0;
extern std::vector<std::string> createCopym1_m1;
extern std::vector<std::string> createCopy10;
extern std::vector<std::string> createCopy60;
extern std::vector<std::string> print0;
extern std::vector<std::string> printm1;
extern std::vector<std::string> print6;
extern std::vector<std::string> print10;
extern std::vector<std::string> printAll;
extern std::vector<std::string> deletem1;
extern std::vector<std::string> delete0;
extern std::vector<std::string> delete10;
extern std::vector<std::string> deleteAll;
extern std::vector<std::string> setValue0_0_23;
extern std::vector<std::string> setValue10_0_23;
extern std::vector<std::string> setValue10_10_23;
extern std::vector<std::string> setValuem1_m1_23;
extern std::vector<std::string> setValue1_m1_23;
extern std::vector<std::string> getValue0_1;
extern std::vector<std::string> getValue1_0;
extern std::vector<std::string> getValuem1_1;
extern std::vector<std::string> getValue0_m1;
extern std::vector<std::string> getValue1_2;
extern std::vector<std::string> getValue10_4;
extern std::vector<std::string> getValue6_3;
extern std::vector<std::string> getValue10_10;
extern std::vector<std::string> help;
}

namespace wrongAmountStub
{
extern std::vector<std::string> goToSmall;
extern std::vector<std::string> createToSmall;
extern std::vector<std::string> createDefToSmall;
extern std::vector<std::string> createCopy0ToSmall;
extern std::vector<std::string> printToSmall;
extern std::vector<std::string> deleteToSmall;
extern std::vector<std::string> getValue0ToSmall;
extern std::vector<std::string> setValue0_0ToSmall;
extern std::vector<std::string> wrongCommandToSmall;

extern std::vector<std::string> goToBig;
extern std::vector<std::string> createToBig;
extern std::vector<std::string> createDefToBig;
extern std::vector<std::string> createCopy0ToBig;
extern std::vector<std::string> printToBig;
extern std::vector<std::string> deleteToBig;
extern std::vector<std::string> deleteAllToBig;
extern std::vector<std::string> getValue0ToBig;
extern std::vector<std::string> setValue0_0ToBig;
extern std::vector<std::string> wrongCommandToBig;
}

namespace wrongTypeStub
{
extern std::vector<std::string> goZ;
extern std::vector<std::string> createZZZ;
extern std::vector<std::string> createDefZ;
extern std::vector<std::string> createCopyZZ;
extern std::vector<std::string> printZ;
extern std::vector<std::string> deleteZ;
extern std::vector<std::string> getValueZZ;
extern std::vector<std::string> setValue0ZZZ;
}
