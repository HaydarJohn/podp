#pragma once


#include <string>

enum class EventType
{
    ERROR
};

class Event
{
private:
    EventType type;
    std::string eventInfo;
public:
    Event(EventType type,std::string eventInfo);
    ~Event();
    EventType getType();
};


