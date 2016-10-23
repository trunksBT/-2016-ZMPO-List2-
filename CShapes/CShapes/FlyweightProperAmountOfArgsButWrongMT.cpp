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
class CCFlyweightProperAmountOfArgsButWrongMT : public testing::Test
{
protected:
    virtual void SetUp()
    {
        rcVal = RETURN_CODE::ERROR;
    }

    virtual void TearDown()
    {}
protected:
    CFlyweight application;
    RETURN_CODE rcVal;
};

TEST_F(CCFlyweightProperAmountOfArgsButWrongMT, createDefZ_OnEmptyCCFlyweight_Expect_ERROR)
{
    RETURN_CODE expVal = RETURN_CODE::ERROR;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongTypeStub::createDefZ)
    });

    ASSERT_EQ(expVal, rcVal);

}

TEST_F(CCFlyweightProperAmountOfArgsButWrongMT, createCopyZZ_OnEmptyCCFlyweight_Expect_ERROR)
{
    RETURN_CODE expVal = RETURN_CODE::ERROR;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongTypeStub::createCopyZZ)
    });

    ASSERT_EQ(expVal, rcVal);

}

TEST_F(CCFlyweightProperAmountOfArgsButWrongMT, printZ_OnEmptyCCFlyweight_Expect_ERROR)
{
    RETURN_CODE expVal = RETURN_CODE::ERROR;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongTypeStub::printZ)
    });

    ASSERT_EQ(expVal, rcVal);

}

TEST_F(CCFlyweightProperAmountOfArgsButWrongMT, deleteZ_OnEmptyCCFlyweight_Expect_ERROR)
{
    RETURN_CODE expVal = RETURN_CODE::ERROR;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongTypeStub::deleteZ)
    });

    ASSERT_EQ(expVal, rcVal);

}

TEST_F(CCFlyweightProperAmountOfArgsButWrongMT, getValueZZ_OnEmptyCCFlyweight_Expect_ERROR)
{
    RETURN_CODE expVal = RETURN_CODE::ERROR;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongTypeStub::getValueZZ)
    });

    ASSERT_EQ(expVal, rcVal);

}

TEST_F(CCFlyweightProperAmountOfArgsButWrongMT, setValue0ZZZ_OnEmptyCCFlyweight_Expect_ERROR)
{
    RETURN_CODE expVal = RETURN_CODE::ERROR;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongTypeStub::setValue0ZZZ)
    });

    ASSERT_EQ(expVal, rcVal);

}

TEST_F(CCFlyweightProperAmountOfArgsButWrongMT, createZZZ_OnEmptyCCFlyweight_Expect_ERROR)
{
    RETURN_CODE expVal = RETURN_CODE::ERROR;

    rcVal = getFinalResultCode
    ({
        application.interpretCommand(wrongTypeStub::createZZZ)
    });

    ASSERT_EQ(expVal, rcVal);

}

}
