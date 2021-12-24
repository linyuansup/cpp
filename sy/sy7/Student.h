#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED
#include "Person.h"
class Student : virtual public Person
{
protected:
    string major, grade;

public:
    Student(string name = 0, string id = 0, string sex = 0, string major = 0, string grade = 0);
    string get_major();
    string get_grade();
    void print_info();
};
#endif