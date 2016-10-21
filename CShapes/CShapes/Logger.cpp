#include "stdafx.h"
#include "Logger.h"

namespace
{
constexpr bool PRINT_CTORS = true;
constexpr bool REPLY_COMMAND = true;
}

Logger::Logger()
{}

Logger::~Logger()
{}

Logger& Logger::operator<<(std::string inLog)
{
    if (PRINT_CTORS && REPLY_COMMAND)
    {
        std::cout << inLog;
    }
    return info();
}

Logger& Logger::info()
{
    static Logger member;
    return member;
}
