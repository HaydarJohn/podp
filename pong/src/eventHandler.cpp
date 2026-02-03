#include"eventHandler.h"



// TODO: Make a log class and log events according to log levels


// REMINDER: always remember to initilize static member variables before doing any shenenigans
EventHandler* EventHandler::instancePtr = nullptr;
std::mutex EventHandler::mutex;

EventHandler::EventHandler()
{

}

EventHandler::~EventHandler()
{

}

EventHandler* EventHandler::getInstance()
{
    if (instancePtr == nullptr) {
        std::lock_guard<std::mutex> lock(mutex);
        if (instancePtr == nullptr) {
            instancePtr = new EventHandler();
        }
    }
    return instancePtr;
}


void EventHandler::pushEvent(Event_Type type,std::string eventInfo)
{

}

void EventHandler::subscibeEvent(Event_Type type,void (*funct)(Event))
{

}    

bool EventHandler::processEvents()
{
    // TODO: implement
    return true;
}