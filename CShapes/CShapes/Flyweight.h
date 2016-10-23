#pragma once

#include <string>
#include <vector>
#include <map>
#include "Point.hpp"
#include "Utils.hpp"
#include "Rectangle.h"

class CFlyweight
{
public:
    CFlyweight();
    explicit CFlyweight(int inPointCacheSize, int inShapeCacheSize);
    ~CFlyweight();
public:
    static RETURN_CODE interpretCommand(std::vector<std::string>& inCommand);
public:
   static void releaseResources();
public:
    static CShape** pointCache_;
    static int sizeOfPointCache_;
    static std::map<int, bool> isInitializedPointCache_;

    static CShape** shapeCache_;
    static int sizeOfShapeCache_;
    static std::map<int, bool> isInitializedShapeCache_;
private:
    static void initPointCache(int inCacheSize);
    static void initShapesCache(int inCacheSize);
};

