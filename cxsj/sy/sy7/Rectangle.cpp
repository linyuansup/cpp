#include <Rectangle.h>
Rectangle::Rectangle(int x, int y, int width, int length) : Shape(x, y)
{
    this->width = width;
    this->length = length;
}
double Rectangle::Getarea()
{
    return width * length;
}
double Rectangle::Getperimeter()
{
    return (width + length) * 2;
}