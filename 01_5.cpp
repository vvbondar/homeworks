#include <iostream>
#include <math.h>

using namespace std;

bool IsCbrtOfInt(int n)
{
    return cbrt(n) == (int)cbrt(n);
}

int main()
{
   for(int i = 1; i <= 1000000; i++)
   {
       if(IsCbrtOfInt(i))
       {
           cout.width(7);
           cout << i;
           cout << " is a cube root of ";
           cout.width(3);
           cout << cbrt(i) << endl;
       }
   }
   return 0;
}