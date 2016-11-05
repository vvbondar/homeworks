#include <iostream>
#include <math.h>

using namespace std;

struct Circle
{
    double r, x, y;
    Circle()
    {
        Init();
    }

    void Init()
    {
        cout << "Enter a radius: ";
        cin >> r;
        cout << "X coord: ";
        cin >> x;
        cout << "Y coord: ";
        cin >> y;
        cout << "OK\n\n";
    }
};

bool IsCrossing(Circle c1, Circle c2)
{
    return (c1.r + c2.r > (sqrt(pow(c1.x+c2.x, 2) + pow(c1.y+c2.y, 2))));
}

int main()
{
   Circle c1, c2;

   cout << "Following circles ARE";
   if(!IsCrossing(c1, c2))
       cout << "NOT";
   cout << " crossing." << endl;
   return 0;
}
