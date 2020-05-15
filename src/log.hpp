#ifndef LOG_H
#define LOG_H
#include <iostream>
#include <string>
class Log
{
public:
    static void LogLine(std::string _message);
    Log();
    ~Log();
};

#endif