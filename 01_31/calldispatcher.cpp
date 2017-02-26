#include "object.h"
#include "calldispatcher.h"

CallDispatcher::CallDispatcher()
{
    //...
}

mmsrIter CallDispatcher::FindConnection(srType sender, srType reciever)
{
    for(mmsrIter it = m_sheet.begin(); it != m_sheet.end(); ++it)
    {
        if(it->first == sender)
        {
            if(it->second == reciever)
            {
                return it;
            }
            else
            {
                continue;
            }
        }
    }
    return m_sheet.end();
}

void CallDispatcher::connect(Object *sender, const std::string& singal, Object *receiver, const std::string& slot)
{
    srType sndr_pair = std::make_pair(sender, singal);
    srType rcvr_pair = std::make_pair(receiver, slot);

    m_sheet.insert(std::make_pair(sndr_pair, rcvr_pair));
}

void CallDispatcher::disconnect(Object *sender, const std::string& singal, Object *receiver, const std::string& slot)
{
    mmsrIter it = FindConnection(std::make_pair(sender, singal),
                                 std::make_pair(receiver, slot));

    if(it == m_sheet.end())
    {
        return;
    }

    m_sheet.erase(it);
}



void CallDispatcher::sendSignal(Object *sender, const std::string& singal)
{
    auto signals_range = m_sheet.equal_range(std::make_pair(sender, singal));

    for(auto i = signals_range.first; i != signals_range.second; ++i)
    {
        i->second.first->dispatchMethod(i->second.second);
    }
}


