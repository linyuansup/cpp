#include "Point.h"
#include <cmath>
#include <iostream>
using namespace std;
Point::Point(int _x, int _y)
{
    x = _x;
    y = _y;
}
double Point::dist()
{
    return sqrt(x * x + y * y);
}
void Point::pan(int delta_x, int delta_y)
{
    x += delta_x;
    y += delta_y;
    return;
}
void Point::rotate(double alpha)
{
    alpha = alpha * M_PI / 180;
    double x_new = x * cos(alpha) - y * sin(alpha);
    double y_new = x * sin(alpha) + y * cos(alpha);
    x = x_new;
    y = y_new;
    return;
}
int Point::get_x()
{
    return x;
}
int Point::get_y()
{
    return y;
}
void Point::display()
{
    cout << "(" << x << "," << y << ")" << endl;
    return;
}