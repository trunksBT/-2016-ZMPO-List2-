#pragma once

#include <string>
#include <vector>
#include "Shape.h"

class CPoint : public CShape
{
public:
    CPoint(int inSize);
    explicit CPoint(double xAxis, double yAxis);
    CPoint(CPoint& inVal);
    CPoint(std::string inVal);
    CPoint(int inSize, int inInitVal);
    CPoint(int inSize, std::string inName);
    ~CPoint();
    void copyCtor(CPoint & inVal);
    CPoint& operator=(CPoint& inObj);
    CPoint* clone();
public:
    int getSize() const;
    int getVal(int inIdx) const;
    std::string getName() const;
    std::string toString() override;
    std::string getType() override;
public:
    void setSize(int inNewSize);
    void setName(std::string inName);
    void setVal(int idx, int inNewVal);
public:
    static CPoint* buildNewObj(CPoint & inVal);
    static CPoint* buildNewObj(int inSize);
    static CPoint* buildNewObj(int inSize, std::string inName);
    static CPoint* buildNewObj(int inSize, int inInitValue);
    void initTable(int* inTable, int inSize, int inDefaultVal);
    void initTable();

private:
    void deepCopy(CPoint& inVal);
    void allocateMemory(int inSize);
    void deallocateMemory();
private:
    std::string name_;
    int* memory_;
    int size_;
};
