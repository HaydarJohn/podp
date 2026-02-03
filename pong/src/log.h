#pragma once

#include <iostream>
#include <mutex>

enum class LogLevel
{
    ERROR,
    WARNING,
    INFO
};

// TODO; ADD filelogging later.
// https://stackoverflow.com/questions/30937227/create-directory-in-c
// in this link it mentions after c++ 17 you can use <filesystem>
// WARNING: I made the desicion to make this class singleton.
// If you have any question look at the comments at eventHandler.h
class Logger
{
private:
    LogLevel level;     // Current Log Level That set. Default Value INFO initilized in constructor.

    static Logger* instancePtr;
    static std::mutex mutex;

    Logger();
public:
    Logger(const Logger &obj) = delete;
    ~Logger();

    static Logger* getInstance();

    void log(LogLevel loglevel,std::string message);
    void setLogLevel(LogLevel logLevel);
};
