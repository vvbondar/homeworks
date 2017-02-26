#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include <memory>
#include <vector>
#include "eventlistener.h"
#include "event.h"

class EventManager
{
public:
    static EventManager& getInstance();

    void publishEvent(const Event& ev);
    void addListener(std::shared_ptr<EventListener> &listener/*, const vector<EVENT_TYPE>& ev_type_list*/);
    void removeListener(std::shared_ptr<EventListener>& listener/*, const vector<EVENT_TYPE>& ev_type_list*/);
    size_t getListenersCount();
private:
    EventManager() = default;
    EventManager(const EventManager&) = delete;
    EventManager& operator=(const EventManager&) = delete;
    std::vector<std::weak_ptr<EventListener>> m_listeners;
    bool Exists(const std::shared_ptr<EventListener> &listener);
    std::vector<std::weak_ptr<EventListener>>::iterator findListener(const std::shared_ptr<EventListener> &listener);
};
#endif // EVENTMANAGER_H
