#include <iostream>
#include <cassert>
#include <ctime>

using namespace std;

template<typename T>
size_t count_if(T* arr, size_t length, bool(*p)(const T& elem))
{
    size_t count = 0;
    for (size_t i = 0; i < length; ++i)
    {
        if(p(arr[i]))
        {
            count++;
        }
    }
    return count;
}

template<typename T>
bool is_sorted(T* arr, size_t length)
{
    for (size_t i = 0; i < length - 1; ++i)
    {
        if(arr[i] > arr[i + 1])
        {
            return false;
        }
    }
    return true;
}

template<typename T>
bool IsPositive(const T& value)
{
    return value > 0;
}

int main()
{
    srand(time(0));

    size_t array_size = 15;
    int array[array_size];

    for (size_t i = 0; i < array_size; ++i)
    {
        array[i] = rand() % 1001 - 500;
        //cout << array[i] << " ";
    }

    array[rand() % (array_size + 1)] = -1;

    assert(IsPositive(99));
    assert(count_if(array, array_size, IsPositive) > 0);
    assert(!is_sorted(array, array_size));

    for (size_t i = 0; i < array_size; ++i)
    {
        array[i] = i;
        //cout << array[i] << " ";
    }

    assert(is_sorted(array, array_size));

    cout << "<ASSERTIONS PASSED>" << endl;

    return 0;
}
