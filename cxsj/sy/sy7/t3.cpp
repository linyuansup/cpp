#include "Circle.h"
#include "Rectangle.h"
#include <iostream>
using namespace std;
void show(Shape *s)
{
    cout << "S=" << s->Getarea() << ", C=" << s->Getperimeter() << endl;
}
int main()
{
    Rectangle r(2, 2, 2, 2);
    Circle c(2, 2, 3);
    show(&r);
    show(&c);
    return 0;
}