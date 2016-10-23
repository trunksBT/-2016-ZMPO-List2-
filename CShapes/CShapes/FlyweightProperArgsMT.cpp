#include "stdafx.h"
#include <gtest/gtest.h>

#include <limits>
#include <vector>
#include <string>
#include <utility>

#include "Flyweight.h"
#include "Stub.hpp"
#include "UtilsForMT.h"

using namespace defaultVals;
using namespace assertWrapper;
using namespace funs;

namespace
{
class CFlyweightProperArgsMT : public testing::Test
{
protected:
    virtual void SetUp()
    {
        rcVal = CODE::ERROR;
    }

    virtual void TearDown()
    {}
protected:
    CFlyweight application;
    CODE rcVal;
};

TEST_F(CFlyweightProperArgsMT, gom1m1_OnEmptyCFlyweight_Expect_WRONG_VALUE)
{
    CODE expVal = CODE::ERROR;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::gom1m1)
    });
    std::cout << toString(rcVal);

    ASSERT_EQ(expVal, rcVal);
}

TEST_F(CFlyweightProperArgsMT, gom10_OnEmptyCFlyweight_Expect_WRONG_VALUE)
{
    CODE expVal = CODE::ERROR;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::gom10)
    });
    std::cout << toString(rcVal);

    ASSERT_EQ(expVal, rcVal);
}

TEST_F(CFlyweightProperArgsMT, go0m1_OnEmptyCFlyweight_Expect_WRONG_VALUE)
{
    CODE expVal = CODE::ERROR;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::go0m1)
    });
    std::cout << toString(rcVal);

    ASSERT_EQ(expVal, rcVal);
}

TEST_F(CFlyweightProperArgsMT, go00_OnEmptyCFlyweight_Expect_SEEMS_LEGIT)
{
    CODE expVal = CODE::DONE;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::go00)
    });
    std::cout << toString(rcVal);

    ASSERT_EQ(expVal, rcVal);
}

TEST_F(CFlyweightProperArgsMT, go10_OnEmptyCFlyweight_Expect_SEEMS_LEGIT)
{
    CODE expVal = CODE::DONE;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::go10)
    });
    std::cout << toString(rcVal);

    ASSERT_EQ(expVal, rcVal);
}

TEST_F(CFlyweightProperArgsMT, go01_OnEmptyCFlyweight_Expect_SEEMS_LEGIT)
{
    CODE expVal = CODE::DONE;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::go01)
    });
    std::cout << toString(rcVal);

    ASSERT_EQ(expVal, rcVal);
}

TEST_F(CFlyweightProperArgsMT, go10_go10_g01_OnEmptyCFlyweight_Expect_SEEMS_LEGIT)
{
    CODE expVal = CODE::DONE;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::go10),
        application.interpretCommand(stub::go10),
        application.interpretCommand(stub::go01)

    });
    std::cout << toString(rcVal);

    ASSERT_EQ(expVal, rcVal);
}
//
//TEST_F(CFlyweightProperArgsMT, go66_OnEmptyCFlyweight_Expect_SEEMS_LEGIT)
//{
//    CODE expVal = CODE::ERROR;
//
//    rcVal = getFinalResultCode
//    ({
//        application.interpretCommand(stub::go66)
//    });
//    std::cout << toString(rcVal);
//
//    ASSERT_EQ(expVal, rcVal);
//}
//
//TEST_F(CFlyweightProperArgsMT, go60_OnEmptyCFlyweight_Expect_SEEMS_LEGIT)
//{
//    CODE expVal = CODE::ERROR;
//
//    rcVal = getFinalResultCode
//    ({
//        application.interpretCommand(stub::go60)
//    });
//    std::cout << toString(rcVal);
//
//    ASSERT_EQ(expVal, rcVal);
//}
//
//TEST_F(CFlyweightProperArgsMT, go06_OnEmptyCFlyweight_Expect_SEEMS_LEGIT)
//{
//    CODE expVal = CODE::ERROR;
//
//    rcVal = getFinalResultCode
//    ({
//        application.interpretCommand(stub::go06)
//    });
//    std::cout << toString(rcVal);
//
//    ASSERT_EQ(expVal, rcVal);
//}
//
//TEST_F(CFlyweightProperArgsMT, go1000_1000_OnEmptyCFlyweight_Expect_SEEMS_LEGIT)
//{
//    CODE expVal = CODE::DONE;
//
//    rcVal = getFinalResultCode
//    ({
//        application.interpretCommand(stub::go1000_1000)
//    });
//    std::cout << toString(rcVal);
//
//    ASSERT_EQ(expVal, rcVal);
//}
///////////////////////////////
//
//TEST_F(CFlyweightProperArgsMT, getFinalResultCode_createDef_Expect_DONE)
//{
//    CODE expVal = CODE::DONE;
//
//    rcVal = getFinalResultCode
//    ({
//        application.interpretCommand(stub::createDef0),
//        application.interpretCommand(stub::createDef0),
//        application.interpretCommand(stub::createDef0)
//    });
//
//    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
//
//}
//
//TEST_F(CFlyweightProperArgsMT, emptyCommand_Expect_ERROR)
//{
//    CODE expVal = CODE::ERROR;
//
//    rcVal = getFinalResultCode
//    ({
//        application.interpretCommand(stub::emptyCommand)
//    });
//
//    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
//
//}
//
//TEST_F(CFlyweightProperArgsMT, noCommand_Expect_ERROR)
//{
//    CODE expVal = CODE::ERROR;
//
//    rcVal = getFinalResultCode
//    ({
//        application.interpretCommand(stub::noCommand)
//    });
//
//    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
//
//
//}
//
//TEST_F(CFlyweightProperArgsMT, getFinalResultCode_createDef_Expect_ERROR)
//{
//    CODE expVal = CODE::ERROR;
//
//    rcVal = getFinalResultCode
//    ({
//        application.interpretCommand(stub::createDef0),
//        application.interpretCommand(stub::createDefm1),
//        application.interpretCommand(stub::createDef0)
//    });
//
//    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
//}
//
//TEST_F(CFlyweightProperArgsMT, create1_5_Name_OnEmptyCFlyweight_Expect_DONE)
//{
//    CODE expVal = CODE::DONE;
//
//    rcVal = getFinalResultCode
//    ({
//        application.interpretCommand(stub::create1_5_Name)
//    });
//
//    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
//
//}
//
//TEST_F(CFlyweightProperArgsMT, create1_m5_Name_OnEmptyCFlyweight_Expect_ERROR)
//{
//    CODE expVal = CODE::ERROR;
//
//    rcVal = getFinalResultCode
//    ({
//        application.interpretCommand(stub::create1_m5_Name)
//    });
//
//    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
//
//}
//
//TEST_F(CFlyweightProperArgsMT, createm1_5_Name_OnEmptyCFlyweight_Expect_DONE)
//{
//    CODE expVal = CODE::ERROR;
//
//    rcVal = getFinalResultCode
//    ({
//        application.interpretCommand(stub::createm1_5_Name)
//    });
//
//    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
//
//}
//
//TEST_F(CFlyweightProperArgsMT, create6_5_Name_Name_OnEmptyCFlyweight_Expect_DONE)
//{
//    CODE expVal = CODE::DONE;
//
//    rcVal = getFinalResultCode
//    ({
//        application.interpretCommand(stub::create6_5_Name)
//    });
//
//    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
//
//}
//
//TEST_F(CFlyweightProperArgsMT, createDefm1_OnEmptyCFlyweight_Expect_ERROR)
//{
//    CODE expVal = CODE::ERROR;
//    
//    rcVal = getFinalResultCode
//    ({
//        application.interpretCommand(stub::createDefm1)
//    });
//
//    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
//
//}
//
//TEST_F(CFlyweightProperArgsMT, createDef0_OnEmptyCFlyweight_Expect_DONE)
//{
//    CODE expVal = CODE::DONE;
//
//    rcVal = getFinalResultCode
//    ({
//        application.interpretCommand(stub::createDef0)
//    });
//
//    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
//
//}
//
//TEST_F(CFlyweightProperArgsMT, createDef6_OnEmptyCFlyweight_Expect_ERROR)
//{
//    CODE expVal = CODE::ERROR;
//
//    rcVal = getFinalResultCode
//    ({
//        application.interpretCommand(stub::createDef6)
//    });
//
//    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
//
//}
//
//TEST_F(CFlyweightProperArgsMT, createCopy01_Expect_ERROR)
//{
//    CODE expVal = CODE::ERROR;
//
//    rcVal = getFinalResultCode
//    ({
//        application.interpretCommand(stub::createCopy10)
//    });
//
//    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
//
//}
//
//TEST_F(CFlyweightProperArgsMT, print_OnEmptyCFlyweight_Expect_ERROR)
//{
//    CODE expVal = CODE::ERROR;
//
//    rcVal = getFinalResultCode
//    ({
//        application.interpretCommand(stub::print0)
//    });
//
//    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
//
//}
//
//TEST_F(CFlyweightProperArgsMT, deleteAll_Expect_ERROR)
//{
//    CODE expVal = CODE::ERROR;
//
//    rcVal = getFinalResultCode
//    ({
//        application.interpretCommand(stub::deleteAll)
//    });
//
//    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
//
//}
//
//TEST_F(CFlyweightProperArgsMT, printAll_Expect_DONE)
//{
//    CODE expVal = CODE::DONE;
//
//    rcVal = getFinalResultCode
//    ({
//        application.interpretCommand(stub::printAll),
//    });
//
//    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
//
//}
//
//TEST_F(CFlyweightProperArgsMT, help_Expect_DONE)
//{
//    CODE expVal = CODE::DONE;
//
//    rcVal = getFinalResultCode
//    ({
//        application.interpretCommand(stub::help)
//    });
//
//    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
//
//}

}

