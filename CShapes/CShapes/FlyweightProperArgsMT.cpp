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
    {
        application.releaseResources();
    }
protected:
    CFlyweight application;
    CODE rcVal;
};
//
//TEST_F(CFlyweightProperArgsMT, gom1m1_OnEmptyCFlyweight_Expect_WRONG_VALUE)
//{
//    CODE expVal = CODE::ERROR;
//
//    rcVal = getFinalResultCode
//    ({
//        application.interpretCommand(stub::gom1m1)
//    });
//    std::cout << toString(rcVal);
//
//    ASSERT_EQ(expVal, rcVal);
//}
//
//TEST_F(CFlyweightProperArgsMT, gom10_OnEmptyCFlyweight_Expect_WRONG_VALUE)
//{
//    CODE expVal = CODE::ERROR;
//
//    rcVal = getFinalResultCode
//    ({
//        application.interpretCommand(stub::gom10)
//    });
//    std::cout << toString(rcVal);
//
//    ASSERT_EQ(expVal, rcVal);
//}
//
//TEST_F(CFlyweightProperArgsMT, go0m1_OnEmptyCFlyweight_Expect_WRONG_VALUE)
//{
//    CODE expVal = CODE::ERROR;
//
//    rcVal = getFinalResultCode
//    ({
//        application.interpretCommand(stub::go0m1)
//    });
//    std::cout << toString(rcVal);
//
//    ASSERT_EQ(expVal, rcVal);
//}
//
//TEST_F(CFlyweightProperArgsMT, go00_OnEmptyCFlyweight_Expect_SEEMS_LEGIT)
//{
//    CODE expVal = CODE::DONE;
//
//    rcVal = getFinalResultCode
//    ({
//        application.interpretCommand(stub::go00)
//    });
//    std::cout << toString(rcVal);
//
//    ASSERT_EQ(expVal, rcVal);
//}
//
//TEST_F(CFlyweightProperArgsMT, go10_OnEmptyCFlyweight_Expect_SEEMS_LEGIT)
//{
//    CODE expVal = CODE::DONE;
//
//    rcVal = getFinalResultCode
//    ({
//        application.interpretCommand(stub::go10)
//    });
//    std::cout << toString(rcVal);
//
//    ASSERT_EQ(expVal, rcVal);
//}
//
//TEST_F(CFlyweightProperArgsMT, go01_OnEmptyCFlyweight_Expect_SEEMS_LEGIT)
//{
//    CODE expVal = CODE::DONE;
//
//    rcVal = getFinalResultCode
//    ({
//        application.interpretCommand(stub::go01)
//    });
//    std::cout << toString(rcVal);
//
//    ASSERT_EQ(expVal, rcVal);
//}
//
//TEST_F(CFlyweightProperArgsMT, go66_OnEmptyCFlyweight_Expect_SEEMS_LEGIT)
//{
//    CODE expVal = CODE::DONE;
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
//    CODE expVal = CODE::DONE;
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
//    CODE expVal = CODE::DONE;
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
//TEST_F(CFlyweightProperArgsMT, createPoint1_1y5_5y5_Expect_SEEMS_LEGIT)
//{
//    CODE expVal = CODE::DONE;
//
//    rcVal = getFinalResultCode
//    ({
//        application.interpretCommand(stub::go66),
//        application.interpretCommand(stub::createPoint1_1y5_5y5)
//    });
//    std::cout << toString(rcVal);
//
//    ASSERT_EQ(expVal, rcVal);
//}
//
//TEST_F(CFlyweightProperArgsMT, createPoint6_1y5_5y5_Expect_SEEMS_LEGIT)
//{
//    CODE expVal = CODE::ERROR;
//
//    rcVal = getFinalResultCode
//    ({
//        application.interpretCommand(stub::go66),
//        application.interpretCommand(stub::createPoint6_1y5_5y5)
//    });
//    std::cout << toString(rcVal);
//
//    ASSERT_EQ(expVal, rcVal);
//}
//
//TEST_F(CFlyweightProperArgsMT, createPoint0_m1y5_5y5_Expect_SEEMS_LEGIT)
//{
//    CODE expVal = CODE::DONE;
//
//    rcVal = getFinalResultCode
//    ({
//        application.interpretCommand(stub::go66),
//        application.interpretCommand(stub::createPoint0_m1y5_5y5)
//    });
//    std::cout << toString(rcVal);
//
//    ASSERT_EQ(expVal, rcVal);
//}
//
//TEST_F(CFlyweightProperArgsMT, createPoint0_1y5_m5y5_Expect_SEEMS_LEGIT)
//{
//    CODE expVal = CODE::DONE;
//
//    rcVal = getFinalResultCode
//    ({
//        application.interpretCommand(stub::go66),
//        application.interpretCommand(stub::createPoint0_1y5_m5y5)
//    });
//    std::cout << toString(rcVal);
//
//    ASSERT_EQ(expVal, rcVal);
//}

////////////////////////////

TEST_F(CFlyweightProperArgsMT, setPoint1_1y5_5y5_Expect_SEEMS_LEGIT)
{
    CODE expVal = CODE::DONE;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::go66),
        application.interpretCommand(stub::setPoint1_1y5_5y5)
    });
    std::cout << toString(rcVal);

    ASSERT_EQ(expVal, rcVal);
}

TEST_F(CFlyweightProperArgsMT, setPoint6_1y5_5y5_Expect_SEEMS_LEGIT)
{
    CODE expVal = CODE::ERROR;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::go66),
        application.interpretCommand(stub::setPoint6_1y5_5y5)
    });
    std::cout << toString(rcVal);

    ASSERT_EQ(expVal, rcVal);
}

TEST_F(CFlyweightProperArgsMT, setPoint0_m1y5_5y5_Expect_SEEMS_LEGIT)
{
    CODE expVal = CODE::DONE;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::go66),
        application.interpretCommand(stub::setPoint0_m1y5_5y5)
    });
    std::cout << toString(rcVal);

    ASSERT_EQ(expVal, rcVal);
}

TEST_F(CFlyweightProperArgsMT, setPoint0_1y5_m5y5_Expect_SEEMS_LEGIT)
{
    CODE expVal = CODE::DONE;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(stub::go66),
        application.interpretCommand(stub::setPoint0_1y5_m5y5)
    });
    std::cout << toString(rcVal);

    ASSERT_EQ(expVal, rcVal);
}

}
