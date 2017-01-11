#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;

struct Circle
{
    double m_r, m_x, m_y;

    Circle(double radius, double x_coord, double y_coord)
        : m_r(radius),
          m_x(x_coord),
          m_y(y_coord)
    { }

    bool IsCrossing(Circle& other)
    {
        double d_centers = sqrt(pow(m_x + other.m_x, 2) + pow(m_y + other.m_y, 2));

        // One circle includes another
        if (m_r > d_centers + other.m_r || other.m_r > d_centers + m_r)
        {
            return false;
        }

        if (m_r + other.m_r > d_centers)
        {
            return true;
        }

        return false;
    }

};

int main()
{
    Circle c1(15, 0, 0);
    Circle c2(14, 0, 0);

    assert(!c1.IsCrossing(c2));

    cout << "The FIRST circle (r = " << c1.m_r << ", center at {" << c1.m_x << "; " << c1.m_y << "}) IS ";

    if(!c1.IsCrossing(c2))
    {
        cout << "NOT ";
    }

    cout << "crossing the SECOND (r = " << c2.m_r << ", center at {" << c2.m_x << "; " << c2.m_y << "})." << endl;

    Circle c3(15, 0, 0);
    Circle c4(2, 14, 0);

    assert(c3.IsCrossing(c4));

    return 0;
}