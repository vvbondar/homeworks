#include <iostream>

using namespace std;

bool IsOdd(int n)
{
    return !(n%2);
}

bool IsOdd_bit(int n)
{
    return !(n&1);
}

int main()
{
    cout << "1. " << IsOdd(3) << endl << "2. " << IsOdd_bit(3) << endl << endl;
    cout << "1. " << IsOdd(4) << endl << "2. " << IsOdd_bit(4) << endl;

    return 0;
}
