#pragma once

#include <string>
#include <vector>
#include "CTable.hpp"
#include "Utils.hpp"

class CFlyweight
{
public:
    CFlyweight();
    ~CFlyweight();
public:
    static ERROR_CODE interpretCommand(std::vector<std::string>& inCommand);
public:
   static void releaseResources();
private:
    static CTable* cache_;
};

