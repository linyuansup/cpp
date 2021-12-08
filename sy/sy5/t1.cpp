#include "Point.h"
#include <iostream>
using namespace std;
int main()
{
    Point p1(2, 0);
    p1.display();
    cout << p1.dist() << endl;
    p1.pan(3, 0);
    p1.display();
    p1.rotate(90);
    p1.display();
    int x = p1.get_x();
    int y = p1.get_y();
    cout << x << " " << y << endl;
    return 0;
}