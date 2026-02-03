#include "event.h"

Event::Event(Event_Type type,std::string eventInfo)
{
    this->type = type;
    this->eventInfo = eventInfo;
}
Event::~Event()
{

}
Event_Type Event::getType()
{
    return this->type;
}