#include "Geography.h"
using namespace std;
int main()
{
    Point p1(-2, 2);
    Point p2(-2, -2);
    p1.show();
    p2.show();
    Line l1(p1, p2);
    l1.show();
    Line l[4];
    l[0] = Line(p1, p2);
    l[1] = Line(-2, -2, 2, -2);
    l[2] = Line(2, -2, 2, 2);
    l[3] = Line(2, 2, -2, 2);
    Polygon p(l, 4);
    p.show();
    return 0;
}