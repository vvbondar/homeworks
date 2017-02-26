#ifndef EVENTLISTENER_H
#define EVENTLISTENER_H

#include "event.h"

class EventListener
{
public:
    virtual void notify(const Event& ev) = 0;

    bool operator==(const EventListener& rhs)
    {
        return this == &rhs;
    }

    virtual ~EventListener() {}
};


#endif // EVENTLISTENER_H
