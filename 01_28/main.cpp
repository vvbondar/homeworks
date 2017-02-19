#include <iostream>
#include <cassert>
#include <bits/stdc++.h>
#include <fstream>
#include "array.h"
#include "forward_list.h"
#include "list.h"

// Containers (summary):
//    - use vector as default container
//    - use array when fixed size is needed
//    - use map when association is needed
//    - use unordered_map when speed is crititcal, but order is not
//    - use set when need fast lookup/insert, order
//    - use multi_* of the above when don't need uniqueness
//    - use algorythm as the 1st resort


// Iterators:
// http://www.cplusplus.com/reference/iterator/

// Links:
// https://channel9.msdn.com/Series/C9-Lectures-Stephan-T-Lavavej-Standard-Template-Library-STL-/C9-Lectures-Introduction-to-STL-with-Stephan-T-Lavavej
// stroustrup.com/Programming/20_containers.ppt

// H/w:
//  1. Sort word frequency in reversed order
//  2. Concatenate all elements in vector<string>
//  3. Create deque? (http://stackoverflow.com/questions/6292332/what-really-is-a-deque-in-stl)

using namespace std;

struct Box1
{
    int value;
    char ch_value;
};

//bool operator<(const Box1 &a, const Box1 &b)
//{
//    return a.value<b.value;
//}

struct Box1Cmp
{
    bool operator()(const Box1 &a, const Box1 &b)
    {
        return a.value<b.value;
    }
};

struct Box
{
    int value;

    Box()
        : value(0)
    {
    }

    Box(int value_)
        : value(value_)
    {
    }

    Box(const Box& obj)
        : value(obj.value)
    {
    }

    Box(Box&& obj) /*noexcept*/
        : value(move(obj.value))
    {
    }

    Box& operator=(const Box& obj)
    {
        value = obj.value;
        return *this;
    }

    Box& operator=(Box&& obj)
    {
        value = move(obj.value);
        return *this;
    }
};


ostream& operator<< (ostream& os, const Box1& rhs)
{
    os << "{" << rhs.value << ": " << rhs.ch_value << "}";// << endl;
    return os;
}

ostream& operator<< (ostream& os, const Box& rhs)
{
    os << rhs.value;
    return os;
}

template<typename T>
ostream& operator<< (ostream& os, const vector<T>& rhs)
{
    os << rhs.size() << ", " << rhs.capacity() << ": { ";
    for (const T& elem : rhs)
    {
        os << (&elem!=&rhs[0] ? ", " : "");
        os << elem;
    }
    os << " }";
    return os;
}

template<typename T>
ostream& operator<< (ostream& os, const my::forward_list<T>& rhs)
{
    os << "{";
    for (const T& elem : rhs)
    {
        os << (&elem!=&(*rhs.begin()) ? ", " : "");
        os << elem;
    }
    os << "}";
    return os;
}

template<typename T, size_t N>
ostream& operator<< (ostream& os, const std::array<T, N>& rhs)
{
    os << "{";
    for (const T& elem : rhs)
    {
        os << (&elem!=&(*rhs.begin()) ? ", " : "");
        os << elem;
    }
    os << "}";
    return os;
}

template<typename T>
ostream& operator<< (ostream& os, const std::forward_list<T>& rhs)
{
    os << "{";
    for (const T& elem : rhs)
    {
        os << (&elem!=&(*rhs.begin()) ? ", " : "");
        os << elem;
    }
    os << "}";
    return os;
}

template<typename T>
ostream& operator<< (ostream& os, const my::list<T>& rhs)
{
    os << "{";
    for (const T& elem : rhs)
    {
        os << (&elem!=&(*rhs.begin()) ? ", " : "");
        os << elem;
    }
    os << "}";
    return os;
}

template<typename K, typename V,
                     typename Hash = std::hash<K>,
                     typename KeyEqual = std::equal_to<K>,
                     typename Allocator = std::allocator< std::pair<const K, V>>>
ostream& operator<< (ostream& os, const unordered_map<K, V, Hash, KeyEqual, Allocator>& rhs)
{
    os << rhs.size() << ": { ";
    for (const pair<K, V>& elem : rhs)
    {
        os << (elem.first!=rhs.begin()->first ? ", " : "");
        os << "(" << elem.first << "->" << elem.second << ")";
    }
    os << " }";
    return os;
}

template<typename K, typename V, typename Cmp = std::less<K>>
ostream& operator<< (ostream& os, const map<K, V, Cmp>& rhs)
{
    os << rhs.size() << ": { ";
    for (const pair<K, V>& elem : rhs)
    {
        os << (elem.first!=rhs.begin()->first ? ", " : "");
        os << "(" << elem.first << "->" << elem.second << ")";
    }
    os << " }";
    return os;
}

struct CmpLen
{
    bool operator()(const std::string& a, const std::string& b) const
    {
        return a.length() < b.length();
    }
};

struct HashT
{
    size_t operator()(const std::string& key) const
    {
        size_t result = 2166136261;

        for (size_t i = 0; i != key.size(); ++i) {
          result = (result * 16777619) ^ key[i];
        }

        return result ^ (1<< key.length());
    }
};

struct EqualT
{
    bool operator()(const std::string& key1, const std::string& key2) const
    {
        return key1==key2;
    }
};

struct Sum {
    Sum() { sum = 0; }
    void operator()(int n) { sum += n; }

    int sum;
};

template<typename T>
struct iter_selector
{
    const string iter_category;
};

template<>
struct iter_selector<std::bidirectional_iterator_tag>
{
    const string iter_category = "bidirectional_iterator";
};

template<>
struct iter_selector<std::random_access_iterator_tag>
{
    const string iter_category = "random_access_iterator";
};

template<>
struct iter_selector<std::input_iterator_tag>
{
    const string iter_category = "input_iterator";
};

template<>
struct iter_selector<std::output_iterator_tag>
{
    const string iter_category = "output_iterator";
};

template<>
struct iter_selector<std::forward_iterator_tag>
{
    const string iter_category = "forward_iterator";
};

template<class Iter>
void test_iter(Iter)
{
    cout << iter_selector<
            typename std::iterator_traits<Iter>::iterator_category>().iter_category << endl;
}

#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])


int main()
{
    //forward_list<int>::iterator.iterator_category;

    cout << "--------SLL--------" << endl;
    my::forward_list<int> fl;

    fl.push_front(42);
    fl.push_front(43);
    fl.push_front(44);

    cout << "fwd_list: ";
    for(auto& elem: fl)
    {
        cout << elem << ' ';
    }

    fl.reverse();

    cout << endl << "reversed: ";
    for(auto& elem: fl)
    {
        cout << elem << ' ';
    }
    cout << endl;

    cout << "--------DLL--------" << endl;
    //cout << "double-ended list: " << endl;
    {
        my::list<int> dlist;

        dlist.push_back(1);
        dlist.push_back(2);
        dlist.push_back(3);

        // TEST should pass when methods are implemented

            //assert(dlist.empty()==false);
        cout << "dlist: " << dlist << endl;
        my::list<int> dlist2 = dlist;
        cout << "dlist2: " << dlist2 << endl;

        assert(dlist.back() ==dlist2.back());
        assert(dlist.front()==dlist2.front());

        cout << "--reversed--" << endl;
        for(auto it = dlist.rbegin(); it!=dlist.rend(); ++it)
        {
            cout << *it << ' ';
        }
        cout << endl;

        {
            my::list<string> list;
            list.push_back("xxx");
            list.pop_back();
            list.push_back("first");
            list.push_back("second");

            list.reverse();

            assert(*(list.begin()) == "second");
            assert(*(--list.end())   == "first");
            cout << "list: " << list << endl;
        }

        cout << *(dlist.rbegin()) << endl;
        assert(dlist.back() ==*(dlist.rbegin()));

        dlist.pop_back();
        cout << "popped back: " << dlist << endl;
        assert(dlist.empty()==false);

        dlist.pop_front();
        cout << "popped front: " << dlist << endl;
        assert(dlist.empty()==false);

        dlist.pop_front();
        cout << "popped front: " << dlist << endl;
        assert(dlist.empty()==true);

        dlist.push_front(11);
        auto it = dlist.begin();
        *(it) = 42;
        cout << "push & modify: " << dlist << endl;

        assert(*(  dlist.begin())   ==dlist.front());
        assert(*(--dlist.end())     ==dlist.back());
        assert(*(  dlist.rbegin())  ==dlist.back());
        assert(*(--dlist.rend())    ==dlist.front());
        assert(42 == dlist.front());

        dlist.pop_back();
        cout << "popped back: " << dlist << endl;
        assert(dlist.empty()==true);

    }

    return 0;
}

