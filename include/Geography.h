#ifndef GEOGRAPHY_H_INCLUDED
#define GEOGRAPHY_H_INCLUDED
class Point
{
private:
    int x, y;

public:
    Point(int _x = 0, int _y = 0);
    int getx();
    int gety();
    void show();
};
class Line
{
private:
    Point p1, p2;

public:
    Line(int x1, int y1, int x2, int y2);
    Line(Point xp1, Point xp2);
    Line();
    double length();
    Point getp1();
    Point getp2();
    void show();
};
class Polygon
{
private:
    Line *p;
    int edges;

public:
    Polygon(Line *, int edge_num);
    Polygon(Point *, int point_num);
    Polygon(const Polygon &);
    double area();
    double perimeter();
    void show();
    ~Polygon();
};
#endif