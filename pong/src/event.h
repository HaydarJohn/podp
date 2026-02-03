#pragma once


#include <string>
#include "log.h"

enum class EventType
{
    ERROR
};

class Event
{
private:
    EventType type;
    LogLevel logLevel;
    std::string eventInfo;
public:
    Event(EventType type,std::string eventInfo);
    ~Event();
    EventType getType();
    LogLevel getLogLevel();
    std::string getMessage();
};


