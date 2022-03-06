#ifndef STUDENT_ASSISTANT_H_INCLUDED
#define STUDENT_ASSISTANT_H_INCLUDED
#include "Student.h"
#include "Assistant.h"
class Student_assistant : public Student, public Assistant
{
public:
    Student_assistant(string name = 0, string id = 0, string sex = 0, string school = 0, double salary = 0, string major = 0, string grade = 0);
    void print_info();
};
#endif