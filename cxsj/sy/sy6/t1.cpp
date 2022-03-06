#include "Mystring.h"
int main()
{
    Mystring s1("Hello World");
    Mystring s2(s1);
    s1.show();
    s2.show();
    return 0;
}