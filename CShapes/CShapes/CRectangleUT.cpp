#include "stdafx.h"
#include <gtest/gtest.h>
#include "Rectangle.h"
#include "Utils.hpp"
#include <limits>
#include <vector>

using namespace defaultVals;
namespace
{
class CRectangleTests : public testing::Test
{
protected:
    virtual void SetUp()
    {}

    virtual void TearDown()
    {}
};

//TEST_F(CRectangleTests, build_withPoint_fst_1_1_snd_4_4)
//{
//    double fstX = 1;
//    double fstY = 1;
//    CPoint* fstPoint = CPoint::buildNewObj(fstX, fstY);
//
//    double sndX = 4;
//    double sndY = 4;
//    CPoint* sndPoint = CPoint::buildNewObj(sndX, sndY);
//
//    CRectangle* rectangle = CRectangle::buildNewObj(fstPoint, sndPoint);
//    std::cout << rectangle->toString() << POST_PRINT;
//
//    ASSERT_EQ(fstX, rectangle->fstGetX());
//    ASSERT_EQ(fstY, rectangle->fstGetY());
//    ASSERT_EQ(sndX, rectangle->sndGetX());
//    ASSERT_EQ(sndY, rectangle->sndGetY());
//
//    delete fstPoint;
//    delete sndPoint;
//    delete rectangle;
//}
//
//TEST_F(CRectangleTests, build_withDoubles_fst_1_1_snd_4_4)
//{
//    double fstX = 1;
//    double fstY = 1;
//    double sndX = 4;
//    double sndY = 4;
//
//    CRectangle* rectangle = CRectangle::buildNewObj(fstX, fstY, sndX, sndY);
//    std::cout << rectangle->toString() << POST_PRINT;
//
//    ASSERT_EQ(fstX, rectangle->fstGetX());
//    ASSERT_EQ(fstY, rectangle->fstGetY());
//    ASSERT_EQ(sndX, rectangle->sndGetX());
//    ASSERT_EQ(sndY, rectangle->sndGetY());
//
//    delete rectangle;
//}

TEST_F(CRectangleTests, build_withCopy_fst_1_1_snd_4_4)
{
    double fstX = 1;
    double fstY = 1;
    double sndX = 4;
    double sndY = 4;

    CRectangle* rectangleFrom = CRectangle::buildNewObj(fstX, fstY, sndX, sndY);
    CRectangle* rectangleTo = CRectangle::buildNewObj(rectangleFrom);
    std::cout << rectangleFrom->toString() << POST_PRINT;
    std::cout << rectangleTo->toString() << POST_PRINT;

    ASSERT_EQ(fstX, rectangleFrom->fstGetX());
    ASSERT_EQ(fstY, rectangleFrom->fstGetY());
    ASSERT_EQ(sndX, rectangleFrom->sndGetX());
    ASSERT_EQ(sndY, rectangleFrom->sndGetY());

    ASSERT_EQ(fstX, rectangleTo->fstGetX());
    ASSERT_EQ(fstY, rectangleTo->fstGetY());
    ASSERT_EQ(sndX, rectangleTo->sndGetX());
    ASSERT_EQ(sndY, rectangleTo->sndGetY());

    delete rectangleFrom;
    delete rectangleTo;
}

}
