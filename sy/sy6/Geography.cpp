#include "Geography.h"
#include <iostream>
#include <cmath>
using namespace std;
Point::Point(int _x, int _y)
{
    x = _x;
    y = _y;
}
int Point::getx()
{
    return x;
}
int Point::gety()
{
    return y;
}
void Point::show()
{
    cout << "(" << x << "," << y << ")" << endl;
}
Line::Line(int x1, int y1, int x2, int y2) : p1(x1, y1), p2(x2, y2)
{
}
Line::Line(Point xp1, Point xp2) : p1(xp1), p2(xp2)
{
}
Line::Line() {}
double Line::length()
{
    double x1 = p1.getx();
    double x2 = p2.getx();
    double y1 = p1.gety();
    double y2 = p2.gety();
    return sqrt((y1 - y2) * (y1 - y2) + (x1 - x2) * (x1 - x2));
}
Point Line::getp1()
{
    return p1;
}
Point Line::getp2()
{
    return p2;
}
void Line::show()
{
    cout << "(" << p1.getx() << "," << p1.gety() << ")" << endl
         << "(" << p2.getx() << "," << p2.gety() << ")" << endl;
}
Polygon::Polygon(Line *l, int edge_num)
{
    edges = edge_num;
    this->p = new Line[edges];
    for (int i = 0; i < edges; i++)
        this->p[i] = l[i];
}
Polygon::Polygon(Point *p, int point_num)
{
    edges = point_num / 2;
    Line *l = new Line[edges];
    for (int i = 0; i < edges; i++)
        l[i] = Line(p[2 * i], p[2 * i + 1]);
    this->p = new Line[edges];
    for (int i = 0; i < edges; i++)
        this->p[i] = l[i];
}
Polygon::Polygon(const Polygon &p)
{
    edges = p.edges;
    this->p = new Line[edges];
    for (int i = 0; i < edges; i++)
        this->p[i] = p.p[i];
}
double Polygon::area()
{
    double sum = 0;
    for (int i = 1; i < edges - 1; i++)
        sum += 0.5 * ((p[0].getp1().getx()) * (p[i].getp1().gety()) + (p[i].getp1().getx()) * (p[i].getp2().gety()) + (p[i].getp2().getx()) * (p[0].getp1().gety()) - (p[0].getp1().gety()) * (p[i].getp1().getx()) - (p[i].getp1().gety()) * (p[i].getp2().getx()) - (p[i].getp2().gety()) * (p[0].getp1().getx()));
    return sum;
}
double Polygon::perimeter()
{
    double sum = 0;
    for (int i = 0; i < edges; i++)
        sum += p[i].length();
    return sum;
}
void Polygon::show()
{
    for (int i = 0; i < edges; i++)
        p[i].show();
    cout << "C = " << perimeter() << ", S = " << area() << endl;
}
Polygon::~Polygon()
{
    delete[] p;
}