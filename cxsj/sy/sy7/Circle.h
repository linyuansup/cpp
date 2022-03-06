#ifndef CIRCLE_H_INCLUDED
#define CIRCLE_H_INCLUDED
#include "Shape.h"
class Circle : public Shape
{
protected:
    int radius;

public:
    Circle(int x = 0, int y = 0, int radius = 0);
    double Getarea();
    double Getperimeter();
};
#endif