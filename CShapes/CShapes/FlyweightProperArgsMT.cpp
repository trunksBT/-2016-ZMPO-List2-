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

namespace
{
class CFlyweightProperArgsMT : public testing::Test
{
protected:
    virtual void SetUp()
    {
        rcVal = std::make_pair(MINUS_ONE, ERROR_CODE::ERROR);
    }

    virtual void TearDown()
    {}
protected:
    CFlyweight application = CFlyweight(DEFAULT_FLYWEIGHT_CACHE_SIZE);
    ResultCode rcVal;
};

TEST_F(CFlyweightProperArgsMT, createDefsm1_OnEmptyCFlyweight_Expect_WRONG_VALUE)
{
    ERROR_CODE expVal = ERROR_CODE::ERROR;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::createDefsm1)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
}

TEST_F(CFlyweightProperArgsMT, createDefs0_OnEmptyCFlyweight_Expect_WRONG_VALUE)
{
    ERROR_CODE expVal = ERROR_CODE::ERROR;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::createDefs0)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
}

TEST_F(CFlyweightProperArgsMT, createDefs1_OnEmptyCFlyweight_Expect_SEEMS_LEGIT)
{
    ERROR_CODE expVal = ERROR_CODE::DONE;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::createDefs1)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
}

TEST_F(CFlyweightProperArgsMT, createDefs6_OnEmptyCFlyweight_Expect_SEEMS_LEGIT)
{
    ERROR_CODE expVal = ERROR_CODE::DONE;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::createDefs6)
    });

    ASSERT_EQ(expVal, std::get<ONE>(rcVal));
}
//
//TEST_F(CFlyweightProperArgsMT, getFinalResultCode_createDef_Expect_DONE)
//{
//    ERROR_CODE expVal = ERROR_CODE::DONE;
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
//    ERROR_CODE expVal = ERROR_CODE::ERROR;
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
//    ERROR_CODE expVal = ERROR_CODE::ERROR;
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
//    ERROR_CODE expVal = ERROR_CODE::ERROR;
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
//    ERROR_CODE expVal = ERROR_CODE::DONE;
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
//    ERROR_CODE expVal = ERROR_CODE::ERROR;
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
//    ERROR_CODE expVal = ERROR_CODE::ERROR;
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
//    ERROR_CODE expVal = ERROR_CODE::DONE;
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
//    ERROR_CODE expVal = ERROR_CODE::ERROR;
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
//    ERROR_CODE expVal = ERROR_CODE::DONE;
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
//    ERROR_CODE expVal = ERROR_CODE::ERROR;
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
//    ERROR_CODE expVal = ERROR_CODE::ERROR;
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
//    ERROR_CODE expVal = ERROR_CODE::ERROR;
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
//    ERROR_CODE expVal = ERROR_CODE::ERROR;
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
//    ERROR_CODE expVal = ERROR_CODE::DONE;
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
//    ERROR_CODE expVal = ERROR_CODE::DONE;
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

