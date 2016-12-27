#include <iostream>

using namespace std;

template<typename T>
bool all_of(T* arr, size_t length, bool(*p)(const T& elem))
{
    for (int i = 0; i < length; ++i)
    {
        if (!(p(arr[i])))
        {
            return false;
        }
    }
    return true;
}

template<typename T>
bool any_of(T* arr, size_t length, bool(*p)(const T& elem))
{
    for (int i = 0; i < length; ++i)
    {
        if(p(arr[i]))
        {
            return true;
        }
    }
}

int main(int argc, char *argv[])
{

    return 0;
}
