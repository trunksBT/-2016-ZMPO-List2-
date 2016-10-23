#pragma once

#include "Shape.h"
#include <string>
#include <vector>

class CRectangle : public CShape
{
public:
    CRectangle();
    CRectangle(int inSize);
    CRectangle(CRectangle& inVal);
    CRectangle(std::string inVal);
    CRectangle(int inSize, int inInitVal);
    CRectangle(int inSize, std::string inName);
    virtual ~CRectangle();
    void copyCtor(CRectangle & inVal);
    CRectangle& operator=(CRectangle& inObj);
    CRectangle* clone();
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
    static CRectangle* buildNewObj();
    static CRectangle* buildNewObj(CRectangle & inVal);
    static CRectangle* buildNewObj(int inSize);
    static CRectangle* buildNewObj(int inSize, std::string inName);
    static CRectangle* buildNewObj(int inSize, int inInitValue);
    void initTable(int* inTable, int inSize, int inDefaultVal);
    void initTable();

private:
    void deepCopy(CRectangle& inVal);
    void allocateMemory(int inSize);
    void deallocateMemory();
private:
    std::string name_;
    int* memory_;
    int size_;
};
