#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED
class Point
{
private:
    int x, y;

public:
    Point(int _x = 0, int _y = 0);
    double dist();
    void pan(int, int);
    void rotate(double);
    int get_x(), get_y();
    void display();
};
#endif