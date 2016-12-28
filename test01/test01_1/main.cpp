#include <iostream>
#include <string>
#include <cassert>

#define ARR_SIZE(a) sizeof(a)/sizeof(a[0])

using namespace std;

template<typename T>
class ImmutableBuffer
{
private:
    const T* m_inner_buffer;

    size_t m_size;

    ImmutableBuffer& operator =(const T& input_array);
    ImmutableBuffer& operator =(const ImmutableBuffer& other);
public:
    ImmutableBuffer(const T* input_array, size_t input_array_size)
        : m_inner_buffer(input_array)
        , m_size(input_array_size)
    {}

    ImmutableBuffer(const ImmutableBuffer& other)
        : m_inner_buffer(other.m_inner_buffer)
        , m_size(other.m_size)
    {}

    size_t getSize() const
    {
        return m_size;
    }

    const T& operator [](size_t index) const
    {
        return m_inner_buffer[index];
    }

    bool operator ==(const ImmutableBuffer<T>& rhs)
    {
        if (getSize() != rhs.getSize())
        {
           return false;
        }

        for (size_t i = 0; i < getSize(); ++i)
        {
            if ((*this)[i] != rhs[i])
            {
               return false;
            }
        }

        return true;
    }

    bool operator !=(const ImmutableBuffer<T>& rhs)
    {
        return !((*this) == rhs);
    }

    ~ImmutableBuffer()
    {
        delete[] m_inner_buffer;
    }
};

template<typename T>
ostream& operator <<(ostream& os, const ImmutableBuffer<T>& obj)
{
    for (size_t i = 0; i < obj.getSize(); ++i)
    {
        os << obj[i];

        if(i < obj.getSize() - 1)
        {
            cout << ", ";
        }
        else
        {
            cout << ".";
        }
    }

    return os;
}

int main()
{
    int test_arr[] = { 5, 1, 19, 65, 49 };
    int test_arr2[] = { 5, 777, 19, 65, 49 };

    ImmutableBuffer<int> foo(test_arr, ARR_SIZE(test_arr));
    ImmutableBuffer<int> bar(foo);

    cout << "foo: " << foo << endl;
    cout << "bar: " << bar << endl;

    cout << endl;

    assert(foo == bar);
    cout << "Buffer equality assert PASSED." << endl;

    ImmutableBuffer<int> thrird(test_arr2, ARR_SIZE(test_arr));

    assert(foo != thrird);
    cout << "Non-equality assert PASSED." << endl;

    ImmutableBuffer<int> quadro = thrird;

    assert(quadro[0] == 5);
    cout << "[]-access assert PASSED." << endl;

    //quadro[1] = 666;
    //quadro = foo;

    return 0;
}
