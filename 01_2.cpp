#include <iostream>

using namespace std;

int SumOfThree(int n)
{
    //Instead of Abs(n) from <cmath>
    if(n < 0)
    {
        n += -(2*n);
    }
    
    if(n/100 == 0 || n > 999)
    {
        cout << "INVALID VALUE" << endl;
        exit(1);
    }
    return n%10 + (n/10)%10 + (n/100)%10;
}

int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;

    cout << "A sum of digits of " << num << " equals " << SumOfThree(num) << "." << endl;

    return 0;
}
