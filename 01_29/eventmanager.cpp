#include "eventmanager.h"
#include <algorithm>
#include <iostream>

using namespace std;

EventManager& EventManager::getInstance()
{
    static EventManager inst;
    return inst;
}

void EventManager::publishEvent(const Event& ev)
{
    for(auto& e : m_listeners)
    {
        if(auto s_ptr = e.lock())
        {
            (*s_ptr).notify(ev);
        }
    }
}

void EventManager::addListener(std::shared_ptr<EventListener>& listener)
{
    std::cout << "Appending listener..." << std::endl;
    if(!listener || Exists(listener))
    {
        std::cout << "Listener already exists!" << std::endl;
        return;
    }

    m_listeners.push_back(std::weak_ptr<EventListener>(listener));
}

void EventManager::removeListener(std::shared_ptr<EventListener>& listener)
{
    std::cout << "Deleting listener..." << std::endl;
    if(!getListenersCount())
    {
        std::cout << "No listeners to delete!" << std::endl;
        return;
    }

    auto it = findListener(listener);

    if(!listener || !Exists(listener) || (*it).expired())
    {
        std::cout << "Listener doesn't exists!" << std::endl;
        return;
    }

    (*it).reset();
    m_listeners.erase(it);
}

size_t EventManager::getListenersCount()
{
    return m_listeners.size();
}

bool EventManager::Exists(const std::shared_ptr<EventListener> &listener)
{
    return findListener(listener) != m_listeners.end();
}

vector<std::weak_ptr<EventListener>>::iterator EventManager::findListener(const std::shared_ptr<EventListener> &listener)
{
    return std::find_if(m_listeners.begin(), m_listeners.end(),
                       [listener](std::weak_ptr<EventListener>& m_listeners_elem)
                       { return listener == m_listeners_elem.lock(); });
}
