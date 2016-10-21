#pragma once

#include <string>
#include <iostream>



class Logger
{
private:
    Logger();
    ~Logger();

public:
    Logger& operator<<(std::string inLog);
    static Logger& info();
};
