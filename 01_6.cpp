#include <iostream>

using namespace std;

//If n is an exponent of 2, (n-1) is a binary number filled with 1.
//A result of bitwise AND of them will be 0.
bool IsExpOf2(int n)
{
    return (n & (n - 1)) == 0;
}

int main()
{
   for(int i = 1; i <= 1500; i++)
   {
       if(IsExpOf2(i))
           cout << i << endl;
   }
   return 0;
}