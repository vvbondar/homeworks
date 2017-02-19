#include <iostream>
#include <list>
#include <unordered_map>
#include <sstream>
#include <cassert>

/* I tried to make efficient double-hashtable cache with priority counting
 * but it needs heavy search method called every time we cross capacity limit
 * (it is obviously not that rare case).
 *
 * It seems senseless comparing to list's pop()/push(). Decided to save last
 * version for history. Just minimize it.

*/

/*
template<typename K, typename V>
class LRUCache
{
    //hope it's approximately 0(n)
    std::unordered_map<K, V> m_storage;
    std::unordered_map<K, unsigned long long> m_appearances;

    const size_t m_storage_max_size;
    unsigned long long m_top_priority;
    bool debug_mode;

    const K getLeastRecentlyUsedKey(const std::unordered_map<K, unsigned long long>& sheet) const
    {
        auto sheet_it = sheet.begin();
        K res = sheet_it->first;
        ++sheet_it;

        for(; sheet_it != sheet.end(); ++sheet_it)
        {
            res = std::min(res, sheet_it->first);
        }
        return res;
    }

    void UpdatePriority(const K& key)
    {
        m_appearances.find(key)->second = m_top_priority;
        ++m_top_priority;
    }
public:
    LRUCache(size_t max_size)
        :m_storage_max_size(max_size)
        ,m_top_priority(0)
        ,debug_mode(false)
    {}

    // put value by key
    void Put(const K& key, const V& value)
    {
        if(!Exists(key))
        {
            if(Size() == m_storage_max_size)
            {
                K key_to_erase = getLeastRecentlyUsedKey(m_appearances);

                if(debug_mode == true)
                {
                    std::cout << "storage is full! erasing [" << key_to_erase << "]["
                            << m_storage.find(key_to_erase)->second << "]" << std::endl;
                }

                m_storage.erase(m_storage.find(key_to_erase));
                m_appearances.erase(m_appearances.find(key_to_erase));
            }

            m_storage.insert(std::make_pair(key, value));
            m_appearances.insert(std::make_pair(key, m_top_priority));

            if(debug_mode == true)
            {
                std::cout << "ins [" << key << "][" << value
                        << "] with priority (" << m_top_priority << ")" << std::endl;
            }

            ++m_top_priority;
        }
        else
        {
            if(debug_mode == true)
            {
                std::cout << "upd [" << key << "][" << value
                        << "] with priority (" << m_top_priority << ")" << std::endl;
            }

            UpdatePriority(key);
        }
    }

    // Retrieves an entry from the cache that has been cached before
    // using put(). Returns the cached entry. Throws exception,
    // if there is no entry with the key K
    const V& Get(const K& key)
    {
        if(!Exists(key))
        {
            throw std::range_error("<ERROR>: Key doesn't exists.");
        }
        else
        {


            if(debug_mode == true)
            {
                std::cout << "got [" << key << "][" << m_storage.find(key)->second
                        << "] with priority (" << m_top_priority
                        << ")" << std::endl;
            }

            UpdatePriority(key);

            return m_storage.find(key)->second;
        }
    }

    // Checks presence of the value by the given key
    bool Exists(const K& key)
    {
        auto key_it = m_storage.find(key);
        if(key_it == m_storage.end())
        {
            return false;
        }

        UpdatePriority(key);

        return true;
    }

    // Clears all the entries in the cache
    void Clear()
    {
        m_storage.clear();
        m_appearances.clear();
    }

    // Returns size
    size_t Size() const
    {
        return m_storage.size();
    }

    void ToggleDebugMode()
    {
        debug_mode = debug_mode ? false : true;
    }
};

*/

template<typename K, typename V>
class LRUCache
{
    typedef std::list<std::pair<K, V>> lru_list;
    typedef std::unordered_map<K, typename lru_list::iterator> lru_map;

    lru_list m_list;
    lru_map  m_map;

    size_t m_capacity;
    bool m_debug_mode = false;

    bool Erase(const K& key)
    {
        if(!Exists(key))
        {
            return false;
        }

        auto it = m_map.find(key);
        m_list.erase(it->second);
        m_map.erase(it);
        return true;
    }

    void ShrinkSize()
    {
        for(auto list_back = (--m_list.end()); Size() > m_capacity; --list_back)
        {
            if(m_debug_mode == true)
            {
                std::cout << "<pop> [" << list_back->first << "]["
                          << list_back->second << "]" << std::endl;
            }

            m_map.erase(list_back->first);
            m_list.pop_back();
        }
    }

public:
    LRUCache(const size_t max_size)
        :m_capacity(max_size)
    {}

    void Put(const K& key, const V& value)
    {
        if(Exists(key))
        {
            Erase(key);
        }

        m_list.push_front(std::make_pair(key, value));
        m_map.insert(std::make_pair(key, m_list.begin()));

        if(m_debug_mode == true)
        {
            std::cout << "<ins> [" << key << "]["
                      << value << "]" << std::endl;
        }

        if(Size() > m_capacity)
        {
            ShrinkSize();
        }
    }

    const V& Get(const K& key)
    {
        if(!Exists(key))
        {
            std::stringstream er;
            er << "<ERROR>: The cache doesn't contains [" << key << "].";
            throw std::out_of_range(er.str());
        }

        auto it = m_map.find(key);
        m_list.splice(m_list.begin(), m_list, it->second);

        if(m_debug_mode == true)
        {
            std::cout << "<got> [" << key << "]["
                      << it->second->second << "]" << std::endl;
        }

        return it->second->second;
    }

    bool Exists(const K& key)
    {
        if(m_map.count(key))
        {
            return true;
        }
        return false;
    }

    void Clear()
    {
        m_list.clear();
        m_map.clear();

        if(m_debug_mode == true)
        {
            std::cout << "<666> [CACHE FLUSHED]" << std::endl;
        }
    }

    size_t Size()
    {
        return m_map.size();
    }

    //works correctly only if both of key and value have operator<<() overloaded
    bool ToggleDebugMode()
    {
        m_debug_mode = m_debug_mode ? false : true;
        return m_debug_mode;
    }
};

int main()
{
    LRUCache<int, std::string> cache(3);

        cache.ToggleDebugMode();

        cache.Put(1, "one");

        assert(cache.Size() == 1);
        assert(cache.Get(1) == "one");

        cache.Put(2, "two");
        cache.Put(3, "three");
        cache.Put(1, "one");
        cache.Put(2, "two");
        cache.Put(3, "three");

        assert(cache.Exists(1) && cache.Exists(2) && cache.Exists(3));

        cache.Put(1, "one");
        cache.Put(2, "two");
        cache.Put(4, "four");
        cache.Put(1, "one");
        cache.Put(4, "four");
        cache.Put(4, "four");
        cache.Put(4, "four");
        cache.Put(4, "four");
        cache.Put(4, "four");
        cache.Put(5, "five");
        cache.Put(3, "three");

        assert(cache.Size() == 3);

        bool value_popped = false;
        try
        {
            cache.Get(2);
        }
        catch(std::exception& e)
        {
            value_popped = true;
            std::cout << e.what() << std::endl;
        }

        assert(value_popped);
        assert(cache.Exists(3) && !cache.Exists(2));

        std::cout << "<ASSERTIONS PASSED>" << std::endl;

        cache.Clear();
}
