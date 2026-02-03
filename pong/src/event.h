#pragma once


#include <string>

enum Event_Type
{
    ERROR
};

class Event
{
private:
    Event_Type type;
    std::string eventInfo;
public:
    Event(Event_Type type,std::string eventInfo);
    ~Event();
    Event_Type getType();
};


