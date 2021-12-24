#include <Circle.h>
#include <cmath>
Circle::Circle(int x, int y, int radius) : Shape(x, y)
{
    this->radius = radius;
}
double Circle::Getarea()
{
    return M_PI * radius * radius;
}
double Circle::Getperimeter()
{
    return 2 * M_PI * radius;
}