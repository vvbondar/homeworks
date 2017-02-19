#include <iostream>
#include <algorithm>
#include <cassert>

template<typename intType>
struct rng_iterator : public std::iterator<std::forward_iterator_tag, intType>
{
private:
    intType m_value;
    size_t m_step;
public:
    rng_iterator(int value, size_t step)
        :m_value(value)
        ,m_step(step)
    {}

    intType& operator*()
    {
        return m_value;
    }

    rng_iterator& operator++()
    {
        m_value += m_step;
        return *this;
    }

    rng_iterator operator++(int)
    {
        rng_iterator tmp(*this);
        ++(*this);
        return tmp;
    }

    bool operator==(const rng_iterator& rhs)
    {
        return m_value == rhs.m_value;
    }

    bool operator!=(const rng_iterator& rhs)
    {
        return this->m_value < rhs.m_value;
    }
};

template<int B, int E, size_t S = 1>
class Range
{
    typedef rng_iterator<int> iterator;
    typedef rng_iterator<const int> const_iterator;

public:
    iterator begin()
    {
        return iterator(B, S);
    }

    iterator end()
    {
        return iterator(E, S);
    }
};

int main()
{
    for (auto& elem : Range<1, 5>())
    {
        std::cout << elem << ' '; // 1 2 3 4
    }

    std::cout << std::endl;

    for (auto& elem : Range<0, 10, 2>())
    {
        std::cout << elem << ' '; //0 2 4 6 8
    }

    std::cout << std::endl;

    for (auto& elem : Range<20, 50, 1000>())
    {
        std::cout << elem << ' '; // 20
    }

    std::cout << std::endl;

    auto r = Range<1, 30>();
    std::cout << count_if(r.begin(), r.end(), [](int e){return e > 20;}) << std::endl; // 9

    assert(*(r.begin()) == 1);
    assert(*(++++r.begin()) == 3);
    assert(*std::find(r.begin(), r.end(), 5) == 5);
    assert(std::find(r.begin(), r.end(), 30) == r.end());
    assert(std::count_if(r.begin(), r.end(), [](int v){ return !(v % 10);}) == 2);

    std::cout << "<ASSERTIONS PASSED>" << std::endl;

    return 0;
}
