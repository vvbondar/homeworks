#include <iostream>
#include <cmath>
#include <vector>
#include <typeinfo>

#define _USE_MATH_DEFINES

using namespace std;

class Shape
{
protected:
    float m_x_coord;
    float m_y_coord;
public:
    Shape()
        : m_x_coord(0)
        , m_y_coord(0)
    {}

    Shape(float x_coord, float y_coord)
        : m_x_coord(x_coord)
        , m_y_coord(y_coord)
    {}
    virtual float getSquare() const = 0;
    virtual ~Shape(){}
};

class Rectangle : public Shape
{
    float m_opp_x_coord;
    float m_opp_y_coord;
    float m_width = abs(m_y_coord - m_opp_y_coord);
    float m_length = abs(m_x_coord - m_opp_x_coord);
public:
    Rectangle()
        : m_opp_x_coord(0)
        , m_opp_y_coord(0)
    {}

    Rectangle(float opp_x_coord, float opp_y_coord)
        : m_opp_x_coord(opp_x_coord)
        , m_opp_y_coord(opp_y_coord)
    {}

    Rectangle(float x_coord, float y_coord, float opp_x_coord, float opp_y_coord)
        : Shape(x_coord, y_coord)
        , m_opp_x_coord(opp_x_coord)
        , m_opp_y_coord(opp_y_coord)
    {}

    float getSquare() const override
    {
        return m_width * m_length;
    }

    float getWidth() const
    {
        return m_width;
    }

    float getLength() const
    {
        return m_length;
    }
};

class Circle : public Shape
{
    float m_radius;
    float m_length = 2 * M_PI * m_radius;
public:
    Circle()
        : m_radius(0)
    {}

    Circle(float radius)
        : m_radius(radius)
    {}

    Circle(float x_coord, float y_coord, float radius)
        : Shape(x_coord, y_coord)
        , m_radius(radius)
    {}

    float getSquare() const override
    {
        return M_PI * pow(m_radius, 2);
    }

    float getLength() const
    {
        return m_length;
    }
};

class Triangle : public Shape
{
protected:
    float m_angle_a;
    float m_angle_b;
    float m_angle_c;
    float m_side;
public:
    Triangle(float angle_a, float angle_b, float angle_c, float side)
        : m_angle_a(angle_a)
        , m_angle_b(angle_b)
        , m_angle_c(angle_c)
        , m_side(side)
    {}

    Triangle(float x_coord, float y_coord, float angle_a, float angle_b, float angle_c, float side)
        : Shape(x_coord, y_coord)
        , m_angle_a(angle_a)
        , m_angle_b(angle_b)
        , m_angle_c(angle_c)
        , m_side(side)
    {}
};

class EquilateralTriangle : public Triangle
{
    float r = sqrt(3) * Triangle::m_side / 6;
public:
    EquilateralTriangle()
        : Triangle(60, 60, 60, 0)
        , r(0)
    {}

    EquilateralTriangle(float side)
        : Triangle(60, 60, 60, side)
    {}

    EquilateralTriangle(float x_coord, float y_coord, float side)
        : Triangle(x_coord, y_coord, 60, 60, 60, side)
    {}

    float getSquare() const override
    {
        return 3 * sqrt(3) * pow(r, 2);
    }
};

int main()
{
    vector<Shape*> shapes;
    float overall_square_sum = 0;

    shapes.push_back(new Rectangle(15, 25));
    shapes.push_back(new Circle(10));
    shapes.push_back(new EquilateralTriangle(5));

    for (auto i : shapes)
    {
        cout << "Square of <" << typeid(*i).name() << "> equals " << i->getSquare() << "." << endl;
        overall_square_sum += i->getSquare();
    }

    cout << "\nOverall square sum equals " << overall_square_sum << "." << endl;

    for (auto i : shapes)
    {
        delete i;
    }

    return 0;
}
