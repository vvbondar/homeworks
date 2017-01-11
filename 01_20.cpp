#include <iostream>
#include <cmath>

#define _USE_MATH_DEFINES

using namespace std;

struct Shape_t;

typedef void (*init_ptr_t)(Shape_t*);
typedef float(*get_square_ptr_t)(Shape_t*);

enum SHAPE_TYPE
{
    RECTANGLE,
    CIRCLE,
    E_TRIANGLE,
    R_TRIANGLE,
    I_TRIANGLE
} shape_types;

ostream& operator <<(ostream& os, const SHAPE_TYPE& type)
{
    switch(type)
    {
        case RECTANGLE: return (os << "Rectangle");
        case CIRCLE: return (os << "Circle");
        case E_TRIANGLE: return (os << "Equilateral triangle");
        case R_TRIANGLE: return (os << "Right triangle");
        case I_TRIANGLE: return (os << "Isosceles triangle");
   }
   return (os);
}

struct vtable_t
{
    get_square_ptr_t getSquare_func;
};

struct Shape_t
{
    int x_coord;
    int y_coord;

    vtable_t* vtable;
};

struct Rectangle_t
{
    Shape_t base;
    vtable_t* vtable;

    int opposite_x_coord;
    int opposite_y_coord;
};

struct Circle_t
{
    Shape_t base;
    vtable_t* vtable;

    float radius;
};

struct Triangle_t
{
    Shape_t base;
    vtable_t* vtable;

    float angle_A;
    float angle_B;
    float angle_C;

    float side;
};

struct EquilateralTriangle_t
{
    Triangle_t base;
    vtable_t* vtable;

    float r;    //inner circle radius
};

struct RightTriangle_t
{
    Triangle_t base;
    vtable_t* vtable;

    float cathetus_a;
    float cathetus_b;
};

float getShapeSquare(Shape_t* entity)
{
    return entity->vtable->getSquare_func(entity);
}

float getRectangleSquare(Shape_t* entity)
{
    Rectangle_t* rectangle = (Rectangle_t*)entity;

    return (abs(rectangle->base.x_coord - rectangle->opposite_x_coord) *
            abs(rectangle->base.y_coord - rectangle->opposite_y_coord));
}

float getCircleSquare(Shape_t* entity)
{
    Circle_t* circle = (Circle_t*)entity;

    return (M_PI * pow(circle->radius, 2));
}

//Triangles
float getEquilateralTriangleSquare(Shape_t* entity)
{
    EquilateralTriangle_t* e_triangle = (EquilateralTriangle_t*)entity;

    return (3 * sqrt(3) * pow(e_triangle->r, 2));
}

float getRightTriangleSquare(Shape_t* entity)
{
    RightTriangle_t* r_triangle = (RightTriangle_t*)entity;

    return ((r_triangle->cathetus_a * r_triangle->cathetus_b) / 2);
}

void ShapeInit(Shape_t* thiz)
{
    vtable_t* vptr = new vtable_t;
    thiz->vtable = vptr;
    thiz->vtable->getSquare_func = NULL;

    thiz->x_coord = 0;
    thiz->y_coord = 0;
}

void RectangleInit(Rectangle_t* thiz, float x_coord, float y_coord, float opp_x_coord, float opp_y_coord)
{
    ShapeInit((Shape_t*)thiz);

    vtable_t* vptr = new vtable_t;
    thiz->vtable = vptr;
    thiz->base.vtable->getSquare_func = getRectangleSquare;

    thiz->base.x_coord = x_coord;
    thiz->base.y_coord = y_coord;
    thiz->opposite_x_coord = opp_x_coord;
    thiz->opposite_y_coord = opp_y_coord;
}

void CircleInit(Circle_t* thiz, float x_coord, float y_coord, float radius)
{
    ShapeInit((Shape_t*)thiz);

    vtable_t* vptr = new vtable_t;
    thiz->vtable = vptr;
    thiz->base.vtable->getSquare_func = getCircleSquare;

    thiz->base.x_coord = x_coord;
    thiz->base.y_coord = y_coord;

    thiz->radius = radius;
}

void TriangleInit(Triangle_t* thiz)
{
    ShapeInit((Shape_t*)thiz);

    vtable_t* vptr = new vtable_t;
    thiz->vtable = vptr;
    thiz->base.vtable->getSquare_func = NULL;

    thiz->base.x_coord = 0;
    thiz->base.y_coord = 0;

    thiz->angle_A = 0;
    thiz->angle_B = 0;
    thiz->angle_C = 0;

    thiz->side = 0;
}

void EquilateralTriangleInit(EquilateralTriangle_t* thiz, float x_coord, float y_coord, float side)
{
    TriangleInit((Triangle_t*)thiz);

    vtable_t* vptr = new vtable_t;
    thiz->vtable = vptr;

    thiz->base.base.vtable->getSquare_func = getEquilateralTriangleSquare;

    thiz->base.base.x_coord = x_coord;
    thiz->base.base.x_coord = y_coord;
    thiz->base.side = side;

    thiz->r = sqrt(3) * thiz->base.side / 6;

    thiz->base.angle_A = 60;
    thiz->base.angle_B = 60;
    thiz->base.angle_C = 60;
}

void RightTriangleInit(RightTriangle_t* thiz, float x_coord, float y_coord, float cathetus_a, float cathetus_b)
{
    TriangleInit((Triangle_t*)thiz);

    vtable_t* vptr = new vtable_t;
    thiz->vtable = vptr;

    thiz->base.base.vtable->getSquare_func = getRightTriangleSquare;

    thiz->base.base.x_coord = x_coord;
    thiz->base.base.y_coord = y_coord;

    thiz->cathetus_a = cathetus_a;
    thiz->cathetus_b = cathetus_b;

    thiz->base.side = sqrt(pow(cathetus_a, 2) + pow(cathetus_b, 2));

    thiz->base.angle_C = 90;
    thiz->base.angle_A = asin(cathetus_a / thiz->base.side) * 180 / M_PI;
    thiz->base.angle_B = thiz->base.angle_C - thiz->base.angle_A;
}

//Rectangle case
Shape_t* Create(SHAPE_TYPE type, float x_coord = 0, float y_coord = 0, float param_a = 0, float param_b = 0)
{
    Shape_t* pEntity = NULL;

    if(type == RECTANGLE)
    {
        Rectangle_t* rectangle = new Rectangle_t;
        RectangleInit(rectangle, x_coord, y_coord, param_a, param_b);

        pEntity = (Shape_t*)(void*) rectangle;
    }

    if(type == CIRCLE)
    {
        Circle_t* circle = new Circle_t;
        CircleInit(circle, x_coord, y_coord, param_a);

        pEntity = (Shape_t*)(void*) circle;
    }

    if(type == E_TRIANGLE)
    {
        EquilateralTriangle_t* e_triangle = new EquilateralTriangle_t;
        EquilateralTriangleInit(e_triangle, x_coord, y_coord, param_a);

        pEntity = (Shape_t*)(void*) e_triangle;
    }

    if(type == R_TRIANGLE)
    {
        RightTriangle_t* r_triangle = new RightTriangle_t;
        RightTriangleInit(r_triangle, x_coord, y_coord, param_a, param_b);

        pEntity = (Shape_t*)(void*) r_triangle;
    }

    return pEntity;
}

int main()
{
    size_t s = 4;
    float squares_sum = 0;

    Shape_t* shapes[s] =
    {
         Create(RECTANGLE,  0, 0, 25, 15)
        ,Create(CIRCLE,     0, 0, 10)
        ,Create(E_TRIANGLE, 0, 0, 5)
        ,Create(R_TRIANGLE, 0, 0, 3, 4)
    };

    for (size_t i = 0; i < s; ++i)
    {
        cout << "Square of <" << SHAPE_TYPE(i) << "> equals ";
        cout << getShapeSquare(shapes[i]) << "." << endl;
        squares_sum += getShapeSquare(shapes[i]);
    }

    cout << "\nOverall square sum equals " << squares_sum << "." << endl;

    for (size_t i = 0; i < s; ++i)
    {
        delete shapes[i];
    }

    return 0;
}
