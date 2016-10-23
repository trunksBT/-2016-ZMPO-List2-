#pragma once

#include <string>
#include <vector>
#include <map>
#include "Point.hpp"
#include "Utils.hpp"

class CFlyweight
{
public:
    CFlyweight();
    explicit CFlyweight(int inCacheSize);
    ~CFlyweight();
public:
    static RETURN_CODE interpretCommand(std::vector<std::string>& inCommand);
public:
   static void releaseResources();
public:
    static CPoint** cache_;
    static CShape** shapeCache_;
    static int sizeOfPointCache_;
    static std::map<int, bool> isInitializedPointCache_;
    static int sizeOfRectangleCache_;
    static std::map<int, bool> isInitializedRectangleCache_;
};

