#ifndef CALLDISPATCHER_H
#define CALLDISPATCHER_H

#include <string>
#include <memory>
#include <map>
#include <algorithm>
#include <iostream>



class Object;

typedef std::pair<Object*, std::string> srType;
typedef std::multimap<srType, srType>::iterator mmsrIter;

class CallDispatcher
{
public:
    typedef std::shared_ptr<CallDispatcher> Ptr;
private:
    std::multimap<srType, srType> m_sheet;
public:
    CallDispatcher();

    mmsrIter FindConnection(srType sender, srType reciever);
    void connect(Object* sender, const std::string& singal, Object* receiver, const std::string& slot);
    void disconnect(Object* sender, const std::string& singal, Object* receiver, const std::string& slot);

    void sendSignal(Object* sender, const std::string& singal);

};

#endif // CALLDISPATCHER_H
