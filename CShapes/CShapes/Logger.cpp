#include "stdafx.h"
#include "Logger.h"


Logger::Logger()
{}

Logger::~Logger()
{}

Logger& Logger::operator<<(std::string inLog)
{
    std::cout << inLog;
    return info();
}

Logger& Logger::info()
{
    static Logger member;
    return member;
}
