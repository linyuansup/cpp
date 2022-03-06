#ifndef MYSTRING_H_INCLUDED
#define MYSTRING_H_INCLUDED
#include <iostream>
class Mystring
{
private:
    char *p;
    int len;

public:
    Mystring(char *p = NULL);
    Mystring(Mystring &);
    ~Mystring();
    void show();
};
#endif