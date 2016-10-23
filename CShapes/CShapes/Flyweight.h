#pragma once

#include <string>
#include <vector>
#include <map>
#include "CPoint.hpp"
#include "Utils.hpp"

class CFlyweight
{
public:
    CFlyweight();
    explicit CFlyweight(int inCacheSize);
    ~CFlyweight();
public:
    static ERROR_CODE interpretCommand(std::vector<std::string>& inCommand);
public:
   static void releaseResources();
public:
    static CPoint** cache_;
    static int sizeOfPointCache_;
    static std::map<int, bool> isInitializedPointCache_;
    static int sizeOfRectangleCache_;
    static std::map<int, bool> isInitializedRectangleCache_;
};

