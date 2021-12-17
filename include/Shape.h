#ifndef SHAPE_H_INCLUDED
#define SHAPE_H_INCLUDED
class Shape
{
protected:
    int x, y;

public:
    Shape(int x = 0, int y = 0);
    virtual double Getarea() = 0;
    virtual double Getperimeter() = 0;
};
#endif