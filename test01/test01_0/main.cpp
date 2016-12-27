#include <iostream>
#include <string>
#include <vector>
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

    const T& operator[](size_t index) const
    {
        return m_inner_buffer[index];
    }

    friend ostream& operator <<(ostream& os, const ImmutableBuffer<T>& obj);

    friend bool operator==(const ImmutableBuffer<T>& lhs, const ImmutableBuffer<T>& rhs);

    bool operator !=(const ImmutableBuffer<T>& rhs);

    ~ImmutableBuffer()
    {
        delete[] m_inner_buffer;
    }
};

template<typename T>
bool operator==(const ImmutableBuffer<T>& lhs, const ImmutableBuffer<T>& rhs)
{
    if(lhs.getSize() != rhs.getSize())
    {
       return false;
    }

    for (int i = 0; i < lhs.getSize(); ++i)
    {
        if (lhs[i] != rhs[i])
        {
           return false;
        }
    }

    return true;
}

template<typename T>
bool operator !=(const ImmutableBuffer<T>& lhs, const ImmutableBuffer<T>& rhs)
{
    return !(lhs == rhs);
}

template<typename T>
ostream& operator <<(ostream& os, const ImmutableBuffer<T>& obj)
{
    for (int i = 0; i < obj.getSize(); ++i)
    {
        os << obj[i] << ' ';
    }

    return os;
}

int main(int argv, char* argc[])
{
    int test_arr[] = { 5, 1, 19, 65, 49 };

//    cout << "test_arr:\n";
//    for (int i = 0; i < 5; ++i)
//    {
//        cout << test_arr[i] << ' ';
//    }

//    cout << endl;

//    ImmutableBuffer<int> test_i_b(test_arr, 5);

//    cout << "test_i_b:\n";
//    for (int i = 0; i < 5; ++i)
//    {
//        cout << test_i_b[i] << ' ';
//    }

//    //cout << test_i_b << endl;

//    cout << endl;

//    cout << test_i_b.getSize() << endl;


    ImmutableBuffer<int> foo(test_arr, ARR_SIZE(test_arr));
    //cout << "foo: " << foo << endl;

    ImmutableBuffer<int> bar(foo);
    //cout << "bar: " << bar << endl;

    cout << foo == bar;

    return 0;
}
