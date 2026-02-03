#include "event.h"

Event::Event(EventType type,std::string eventInfo)
{
    this->type = type;
    this->eventInfo = eventInfo;
}
Event::~Event()
{

}
EventType Event::getType()
{
    return this->type;
}