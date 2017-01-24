#include <iostream>
#include <cassert>
#include <ctime>

template<typename T, int N = 16>
class stack
{
    T m_data[N];
    size_t m_last;
public:
    stack()
        :m_data()
        ,m_last(0)
    {}

    void push(const T& value)
    {
        m_data[m_last++] = value;
    }

    T pop()
    {
        return m_data[--m_last];
    }
};

template<int N>
class stack<bool, N>
{
    char m_data[N];
    size_t m_last;
public:
    stack()
        :m_data()
        ,m_last(0)
    {}

    void push(const bool& value)
    {
        int bit_num = m_last / 8;
        int bit_offset = m_last % 8;

        m_data[bit_num] ^= (-value ^ m_data[bit_num]) & (1 << (7 - bit_offset));
        m_last++;
    }

    bool pop()
    {
        int bit_num = --m_last / 8;
        int bit_offset = m_last % 8;

        bool res = (m_data[bit_num] >> (7 - bit_offset)) & 1;

        return res;
    }
};

int main()
{
    srand(static_cast<size_t>(time(0)));

    const size_t size = 32;

    stack<char, size> fat_stack;
    stack<bool, size / 8> slim_stack;

    for (size_t i = 0; i < size; ++i)
    {
        bool rnd = rand() % 2;
        fat_stack.push(rnd);
        slim_stack.push(rnd);
    }

    std::cout << "f | s\n-----" << std::endl;

    for (size_t i = 0; i < size; ++i)
    {
        bool f_st = fat_stack.pop();
        bool s_st = slim_stack.pop();

        std::cout << f_st << " | " << s_st << std::endl;
        assert(f_st == s_st);
    }

    std::cout << "-----" << std::endl;
    std::cout << "<ASSERTION PASSED>" << std::endl;

    return 0;
}
