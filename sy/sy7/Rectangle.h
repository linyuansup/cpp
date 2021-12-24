#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED
#include "Shape.h"
class Rectangle : public Shape
{
protected:
    int width, length;

public:
    Rectangle(int x = 0, int y = 0, int width = 0, int length = 0);
    double Getarea();
    double Getperimeter();
};
#endif