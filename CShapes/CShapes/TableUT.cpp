#include "stdafx.h"
#include <gtest/gtest.h>
#include "CPoint.hpp"
#include "Utils.hpp"
#include <limits>
#include <vector>

using namespace defaultVals;
namespace
{
class CPointTests : public testing::Test
{
protected:
   virtual void SetUp()
   {}

   virtual void TearDown()
   {}
};

TEST_F(CPointTests, clone_Expect_theSameVals_otherAddresses)
{
    CPoint* inVal = CPoint::buildNewObj();
    CPoint* clonedObject = inVal->clone();

    std::cout << inVal->toString() << POST_PRINT;
    std::cout << clonedObject->toString() << POST_PRINT;

    ASSERT_EQ(inVal->getName(), clonedObject->getName());
    ASSERT_EQ(inVal->getSize(), clonedObject->getSize());
    ASSERT_EQ(inVal->getVal(0), clonedObject->getVal(0));
    ASSERT_EQ(inVal->getVal(1), clonedObject->getVal(1));
    ASSERT_EQ(inVal->getVal(2), clonedObject->getVal(2));

    delete inVal;
    delete clonedObject;
}

TEST_F(CPointTests, defCTOR_getSize_DEFAULTSIZE_Expect_DEFAULTSIZE)
{
   CPoint* inVal = CPoint::buildNewObj();
   int expVal = DEFAULT_IN_TABLE_SIZE;

   int rcVal = inVal->getSize();

   ASSERT_EQ(expVal, rcVal);
   delete inVal;
}

TEST_F(CPointTests, defCTOR_getValue_DEFAULT_VALUE_Expect_DEFAULTSIZE)
{
    CPoint* inVal = CPoint::buildNewObj();
    int expVal = DEFAULT_TABLE_VAL;
    int goalIdx = 0;

    int rcVal = inVal->getVal(goalIdx);

    ASSERT_EQ(expVal, rcVal);
    delete inVal;
}

TEST_F(CPointTests, defCTOR_setSize_0_Expect_0)
{
   int inSize = ZERO;
   CPoint* inVal = CPoint::buildNewObj(inSize);
   int expVal = ZERO;

   int rcVal = inVal->getSize();

   ASSERT_EQ(expVal, rcVal);
   delete inVal;
}

TEST_F(CPointTests, copyCTOR_size5_Expect_size5)
{
   int inSize = DEFAULT_IN_TABLE_SIZE;
   int expVal = DEFAULT_IN_TABLE_SIZE;
   CPoint* sourceVal = CPoint::buildNewObj(inSize);

   CPoint* inVal = CPoint::buildNewObj(*sourceVal);
   int rcVal = inVal->getSize();

   ASSERT_EQ(expVal, rcVal);
   delete sourceVal;
   delete inVal;
}

TEST_F(CPointTests, copyCTOR_withAssignCopyOperator_size5_Expect_size5)
{
   int inSize = FIVE;
   int expVal = FIVE;
   CPoint* sourceVal = CPoint::buildNewObj(inSize);

   CPoint* inVal = CPoint::buildNewObj();
   *inVal = *sourceVal;

   int rcVal = inVal->getSize();

   ASSERT_EQ(expVal, rcVal);
   delete sourceVal;
   delete inVal;
}

TEST_F(CPointTests, pushBack_onVector_ofObj_expect_CopyCtor)
{
    std::vector<CPoint> inVector;
    inVector.push_back(CPoint());
    inVector.clear();
    ASSERT_TRUE(true);
}

TEST_F(CPointTests, setVal_defaultCTORed_3_onIdx_0_Expect_3)
{
   int newVal = 500;
   int idxForNewVal = 0;
   CPoint* sourceVal = CPoint::buildNewObj();

   int oldVal = sourceVal->getVal(idxForNewVal);
   sourceVal->setVal(idxForNewVal, newVal);
   int rcVal = sourceVal->getVal(idxForNewVal);

   ASSERT_NE(oldVal, rcVal);
   ASSERT_EQ(newVal, rcVal);
   delete sourceVal;
}

TEST_F(CPointTests, getVal_defaultCTORed_3_onIdx_m1_Expect_LimitMin)
{
   int idx = -1;
   CPoint* sourceVal = CPoint::buildNewObj();

   int rcVal = sourceVal->getVal(idx);

   ASSERT_EQ(std::numeric_limits<int>::min(), rcVal);
   delete sourceVal;
}

TEST_F(CPointTests, print_defaultCTORed)
{
    CPoint* sourceVal = CPoint::buildNewObj();

    std::cout << sourceVal->toString();

    ASSERT_TRUE(true);
    delete sourceVal;
}

TEST_F(CPointTests, print_Copied)
{
    int inSize = FIVE;
    CPoint* sourceVal = CPoint::buildNewObj(inSize);

    CPoint* inVal = CPoint::buildNewObj();
    *inVal = *sourceVal;

    std::cout << sourceVal->toString() << POST_PRINT;
    std::cout << inVal->toString() << POST_PRINT;

    ASSERT_TRUE(true);
    delete inVal;
    delete sourceVal;
}

TEST_F(CPointTests, print_Copied_afterSetValue)
{
    int inSize = FIVE;
    CPoint* sourceVal = CPoint::buildNewObj(inSize);

    CPoint* inVal = CPoint::buildNewObj();
    *inVal = *sourceVal;
    inVal->setVal(ZERO, FIVE);

    std::cout << sourceVal->toString() << POST_PRINT;
    std::cout << inVal->toString() << POST_PRINT;

    ASSERT_TRUE(true);
    delete inVal;
    delete sourceVal;
}

TEST_F(CPointTests, print_Copied_afterSetName)
{
    int inSize = FIVE;
    CPoint* sourceVal = CPoint::buildNewObj(inSize);

    CPoint* inVal = CPoint::buildNewObj();
    *inVal = *sourceVal;
    inVal->setName("SIEMA_" + std::string(DEFAULT_TABLE_NAME));

    std::cout << sourceVal->toString() << POST_PRINT;
    std::cout << inVal->toString() << POST_PRINT;

    ASSERT_TRUE(true);
    delete inVal;
    delete sourceVal;
}

TEST_F(CPointTests, setSize_from_FIVE_onHigher_Expect_TEN)
{
    int inSize = FIVE;
    int newSize = FIVE;
    int expSize = TEN;
    int initValue = FIVE;
    CPoint* sourceVal = CPoint::buildNewObj(inSize, FIVE);

    std::cout << "Before change size" << std::endl;
    std::cout << sourceVal->toString() << std::endl;

    sourceVal->setSize(TEN);

    std::cout << "After change size" << std::endl;
    std::cout << sourceVal->toString() << std::endl;

    ASSERT_EQ(expSize, sourceVal->getSize());
    delete sourceVal;
}

TEST_F(CPointTests, setSize_from_FIVE_onLower_Expect_TWO)
{
    int inSize = FIVE;
    int newSize = TWO;
    int expSize = TWO;
    int initValue = FIVE;
    CPoint* sourceVal = CPoint::buildNewObj(inSize, FIVE);

    std::cout << "Before change size" << std::endl;
    std::cout << sourceVal->toString() << std::endl;

    sourceVal->setSize(newSize);

    std::cout << "After change size" << std::endl;
    std::cout << sourceVal->toString() << std::endl;

    ASSERT_EQ(expSize, sourceVal->getSize());
    delete sourceVal;
}

TEST_F(CPointTests, setSize_from_FIVE_onTheSame_Expect_FIVE)
{
    int inSize = FIVE;
    int newSize = FIVE;
    int expSize = FIVE;
    int initValue = FIVE;
    CPoint* sourceVal = CPoint::buildNewObj(inSize, FIVE);

    std::cout << "Before change size" << std::endl;
    std::cout << sourceVal->toString() << std::endl;

    sourceVal->setSize(newSize);

    std::cout << "After change size" << std::endl;
    std::cout << sourceVal->toString() << std::endl;

    ASSERT_EQ(expSize, sourceVal->getSize());
    delete sourceVal;
}

TEST_F(CPointTests, buildNewObj_FIVE_newName_Expect_FIVE_newName)
{
    int inSize = FIVE;
    std::string inName = "newName";
    int expSize = FIVE;
    std::string expName = "newName";

    CPoint* sourceVal = CPoint::buildNewObj(inSize, inName);

    ASSERT_EQ(expSize, sourceVal->getSize());
    ASSERT_EQ(expName, sourceVal->getName());
    delete sourceVal;
}

}

