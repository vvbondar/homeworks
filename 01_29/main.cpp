#include <iostream>
#include <string>
#include <memory>
#include <cassert>

#include "event.h"
#include "eventlistener.h"
#include "eventmanager.h"

#define _STATUS_ "---MANAGING " << e_mngr.getListenersCount() << " LISTENER(S)"

using namespace std;

struct FileLogger : EventListener
{
    void notify(const Event& ev) override
    {
        cout << __PRETTY_FUNCTION__ << endl;
        cout << ev.getDescription() << endl;
    }
};

struct ConnectionMgr : EventListener
{
    void notify(const Event& ev) override
    {
        cout << __PRETTY_FUNCTION__ << endl;
        cout << ev.getDescription() << endl;
    }
};

struct EventHandler : EventListener
{
    void notify(const Event& ev) override
    {
        cout << __PRETTY_FUNCTION__ << endl;
        cout << ev.getDescription() << endl;
    }
};

int main()
{
    shared_ptr<EventListener> evListener1 = make_shared<FileLogger>();
    shared_ptr<EventListener> evListener2 = make_shared<ConnectionMgr>();
    shared_ptr<EventListener> evListener3 = make_shared<EventHandler>();

    EventManager& e_mngr = EventManager::getInstance();

    e_mngr.addListener(evListener1);
    e_mngr.addListener(evListener2);
    e_mngr.addListener(evListener3);

    assert(e_mngr.getListenersCount() == 3);
    cout << _STATUS_ << endl;
    cout << "================" << endl;

    Event ev1("FIRST_EVENT");
    e_mngr.publishEvent(ev1);
    cout << "================" << endl;

    e_mngr.removeListener(evListener1);
    cout << _STATUS_ << endl;
    e_mngr.removeListener(evListener1);
    cout << "================" << endl;

    e_mngr.addListener(evListener3);
    cout << _STATUS_ << endl;
    e_mngr.removeListener(evListener3);
    cout << "================" << endl;

    Event ev2("SECOND_EVENT");
    e_mngr.publishEvent(ev2);
    cout << _STATUS_ << endl;
    cout << "================" << endl;

    e_mngr.removeListener(evListener2);
    e_mngr.removeListener(evListener2);

    return 0;
}
