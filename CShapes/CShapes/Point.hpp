#pragma once

#include <string>
#include <vector>
#include "Shape.h"

class CPoint : public CShape
{
public:
    explicit CPoint(double xAxis, double yAxis);
    CPoint(const CPoint& inVal);
    virtual ~CPoint();
    CPoint& operator=(const CPoint& inObj);
public:
    double getX() const;
    double getY() const;
    std::string toString() override;
    std::string getType() override;
public:
    void setX(double newX);
    void setY(double newY);
public:
    static CPoint* buildNewObj(double xAxis, double yAxis);

private:
    void copyCtor(const CPoint& inVal);
    void deepCopy(const CPoint& inVal);
    void deallocateMemory();
private:
    double* xAxis_;
    double* yAxis_;
};
