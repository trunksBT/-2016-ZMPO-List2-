#pragma once

#include <string>
#include <iostream>

constexpr bool PRINT_ON = true;
constexpr bool DEBUG_TESTS_ON = true;

class Logger
{
private:
    Logger();
    ~Logger();

public:
    Logger& operator<<(std::string inLog);
    static Logger& info();
};
