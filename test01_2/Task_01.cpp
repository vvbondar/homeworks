#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

template<typename T, size_t _capacity = 0>
class Vector
{
    size_t m_size;
    T* m_inner_array;
public:
    Vector()
        : m_size(_capacity)
        , m_inner_array(new T[_capacity]())
    {}

    Vector(std::initializer_list<T> l)
        : m_size(l.size())
        , m_inner_array(new T[_capacity]())
    {
        std::copy(l.begin(), l.end(), m_inner_array);
    }

    Vector(const Vector& other)
        : m_size(other.m_size)
        , m_inner_array(new T[m_size])
    {
        for (size_t i = 0; i < m_size; ++i)
        {
            m_inner_array[i] = other.m_inner_array[i];
        }
    }

    void push_back(const T& elem)
    {
        m_size++;

        T* temp_arr = new T[m_size]();

        for (size_t i = 0; i < m_size; ++i)
        {
            temp_arr[i] = m_inner_array[i];
        }

        temp_arr[m_size - 1] = elem;

        delete[] m_inner_array;
        m_inner_array = temp_arr;
    }

    size_t size() const
    {
        return m_size;
    }

    size_t capacity() const
    {
        return _capacity;
    }

    T& operator[](size_t pos)
    {
        return m_inner_array[pos];
    }

    const T& operator[](size_t pos) const
    {
        return m_inner_array[pos];
    }

    void insert(size_t pos, const T& value)
    {
        m_size++;

        T* temp_arr = new T[m_size]();

        for (size_t i = 0; i < pos + 1; ++i)
        {
            temp_arr[i] = m_inner_array[i];
        }

        temp_arr[pos] = value;

        for (size_t i = pos + 1; i < m_size + 1; ++i)
        {
            temp_arr[i] = m_inner_array[i - 1];
        }

        delete[] m_inner_array;
        m_inner_array = temp_arr;
    }

    void erase(size_t pos)
    {
        T* temp_arr = new T[--m_size]();

        for (size_t i = 0; i < pos; ++i)
        {
            temp_arr[i] = m_inner_array[i];
        }

        for (size_t i = pos; i < m_size; ++i)
        {
            temp_arr[i] = m_inner_array[i + 1];
        }

        delete[] m_inner_array;
        m_inner_array = temp_arr;
    }

    T& front() const
    {
        return m_inner_array[0];
    }

    T& back() const
    {
        return m_inner_array[m_size - 1];
    }

    bool operator ==(const Vector& rhs) const
    {
        if(m_size != rhs.m_size || _capacity != rhs.capacity())
        {
            return false;
        }

        for (size_t i = 0; i < m_size; ++i)
        {
            if(m_inner_array[i] != rhs.m_inner_array[i])
            {
                return false;
            }
        }

        return true;
    }

    bool operator !=(const Vector& rhs) const
    {
        return !(*this == rhs);
    }

    bool operator <(const Vector& rhs) const
    {
        if(m_size < rhs.size())
        {
            return true;
        }
        else if(m_size == rhs.size())
        {
            for (size_t i = 0; i < m_size; ++i)
            {
                if(m_inner_array[i] >= rhs[i])
                {
                    return false;
                }
            }
            return true;
        }
        return false;
    }

    bool operator <=(const Vector& rhs) const
    {
        return (*this < rhs || *this == rhs);
    }

    bool operator >(const Vector& rhs) const
    {
        return !(*this <= rhs);
    }

    bool operator >=(const Vector& rhs) const
    {
        return !(*this < rhs);
    }

    Vector& operator =(const Vector& rhs)
    {
        if(*this != rhs)
        {
            m_size = rhs.m_size;

            delete[] m_inner_array;
            m_inner_array = new T[rhs.capacity()];

            for (size_t i = 0; i < m_size; ++i)
            {
                m_inner_array[i] = rhs.m_inner_array[i];
            }
        }
        return *this;
    }

    ~Vector()
    {
        if(m_inner_array)
        {
            delete[] m_inner_array;
        }
    }
};

int main()
{
    Vector<int, 5> v_1;
    assert(v_1.size() == v_1.capacity());

    v_1 = { 1, 2, 3, 4, 5 };

    v_1.push_back(99);
    assert(v_1[5] == 99 && v_1.size() == 6);

    Vector<int, 5> v_2(v_1);
    assert(v_2 == v_1);

    v_2.erase(0);
    v_2.erase(0);
    assert(v_2.size() == 4);
    assert(v_2[0] == 3);

    assert(v_2 < v_1);
    assert(v_1 > v_2);

    Vector<int, 5> v_3;
    v_3 = v_1;
    v_3[4]++;
    assert(v_3 > v_1);

    assert(v_2 <= v_1);
    assert(v_1 >= v_2);
    assert(v_1 != v_2);

    v_2.push_back(42);
    v_2.push_back(42);
    v_2.push_back(42);
    assert(v_2 > v_1);

    v_1.insert(0, 42);
    assert(v_1[0] == 42 && v_1.size() == 7);

    assert(v_1[0] == v_1.front());
    assert(v_1[v_1.size() - 1] == v_1.back());

    cout << "<ASSERTIONS PASSED>" << endl;

    return 0;
}
