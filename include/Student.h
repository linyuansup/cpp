#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED
#include <iostream>
class Student
{
private:
    char id[11], name[20];
    double math, physics, english;

public:
    Student(const char *p1 = NULL, const char *p2 = NULL, double _math = 0, double _phy = 0, double _eng = 0);
    void set_info(const char *p1, const char *p2, double _math, double _phy, double _eng);
    double total();
    char *get_id();
    void show_info();
};
#endif