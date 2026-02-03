#include"eventHandler.h"



// TODO: Make a log class and log events according to log levels


// REMINDER: always remember to initilize static member variables before doing any shenenigans
EventHandler* EventHandler::instancePtr = nullptr;
std::mutex EventHandler::mutex;

EventHandler::EventHandler()
{
    this->logger = this->logger->getInstance();
}

EventHandler::~EventHandler()
{
    delete this->instancePtr;
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


void EventHandler::pushEvent(EventType type,std::string eventInfo)
{

}

void EventHandler::subscibeEvent(EventType type,void (*funct)(Event))
{

}    

bool EventHandler::processEvents()
{

    if(this->eventQueue.empty())    return false;

    // Event event = eventQueue.front();
    // this->logger->log(event.getLogLevel(),event.getMessage());
    // eventQueue.pop();

    // this->subscribers

        
    
    
    return true;
}