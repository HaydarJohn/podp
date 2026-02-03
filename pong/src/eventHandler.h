#pragma once
#include <queue>
#include <mutex>
#include <vector>
#include <map>
#include "event.h"

//  https://www.geeksforgeeks.org/cpp/std-mutex-in-cpp/.
//  www.geeksforgeeks.org/cpp/implementation-of-singleton-class-in-cpp/  If you want to make this singleton read this.
//  https://www.geeksforgeeks.org/cpp/queue-cpp-stl/



// TODO: Maybe implement proper event class so you can assign log levels to events. 

class EventHandler
{
private:
    // Why i make two different queue ? because if some error happens i will fix it first in the limited cpu cycle.
    // Then if i have spare i can process other events. It does not matter if you shoot an enemy and it does not register but
    // It plays sound of gun. THat would be weird.

    // WARNING: TODO: queue implementation of cpp not thread safe !!! find replacement or make your own thread safe.
    std::queue<Event> eventQueue;
    std::queue<Event> errorQueue;

    // This may look stupid but it is simply map of Event_type keys mapping to 
    // Every subscriber callback function that interested in that type
    std::map<EventType,std::vector<void(*)(Event)>> subscribers;

    // This part is for singleton . Mutex ensures thread safety.
    static EventHandler* instancePtr;
    static std::mutex mutex;

    // When singleton hide constructor.
    EventHandler(/* args */);

public:

    // This makes it so we delete copy constructor. so there is  no constructor to call.
    EventHandler(const EventHandler& obs) = delete;
    ~EventHandler();

    // This is for singleton.
    static EventHandler* getInstance();

    // Makes internal event object and adds to queue
    void pushEvent(EventType type,std::string eventInfo);

    // A function that takes event type and function so it can callback when that type of event Happens.
    void subscibeEvent(EventType type,void (*funct)(Event));

    bool processEvents();
};
