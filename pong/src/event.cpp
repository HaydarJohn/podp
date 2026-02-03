#include "event.h"

Event::Event(EventType type,std::string eventInfo)
{
    this->type = type;
    this->eventInfo = eventInfo;

    switch (this->type)
    {
        case EventType::ERROR:
        {
            this->logLevel = LogLevel::ERROR;
        }break;
    
        default:
        {
            this->logLevel = LogLevel::INFO;
        }break;
    }
}
Event::~Event()
{

}
EventType Event::getType()
{
    return this->type;
}


LogLevel Event::getLogLevel()
{
    return this->logLevel;
}

std::string Event::getMessage()
{
    return this->eventInfo;
}