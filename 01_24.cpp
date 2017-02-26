#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void Map(vector<T>& container, void (*func)(T&))
{
    for (size_t i = 0; i < container.size(); ++i)
    {
        func(container[i]);
    }
}

template<typename T>
void Filter(vector<T>& container, bool (*pred)(const T&))
{
    size_t rc_index = 0;

    for (size_t i = 0; i < container.size(); ++i)
    {
        if(pred(container[i]))
        {
            container[rc_index++] = container[i];
        }
        else continue;
    }
    container.resize(rc_index);
}

template<typename T>
void Reduce(vector<T>& container, T (*action)(const T&, const T&))
{
    for (size_t i = 1; i < container.size(); ++i)
    {
        container[0] = action(container[0], container[i]);
    }

    container.resize(1);
}

template<typename T>
void PrintArray(T arr)
{
    for (size_t i = 0; i < arr.size(); ++i)
    {
        cout.width(3);
        cout << arr[i] << " ";
    }
    cout << endl << endl;
}

template<typename T>
void Incr(T& a)
{
    ++a;
}

template<typename T>
void Pow2(T& a)
{
    a *= a;
}

template<typename T>
bool IsEven(const T& a)
{
    return !((int)a % 2);
}

template<typename T>
T Sum(const T& a, const T& b)
{
    return a + b;
}

int main()
{
    vector<int> arr(15);

    for (size_t i = 0; i < arr.size(); ++i)
    {
        arr[i] = i + 1;
    }

    cout << "Base array: " << endl;
    PrintArray(arr);

    Map(arr, Incr);
    cout << "Mapped with incrementing: " << endl;
    PrintArray(arr);

    Map(arr, Pow2);
    cout << "Mapped with powering to 2: " << endl;
    PrintArray(arr);

    Filter(arr, IsEven);
    cout << "Filtered by evens: " << endl;
    PrintArray(arr);

    Reduce(arr, Sum);
    cout << "Reduced with summing: " << endl;
    PrintArray(arr);

    return 0;
}
