#ifndef ASSISTANT_H_INCLUDED
#define ASSISTANT_H_INCLUDED
#include "Person.h"
class Assistant : virtual public Person
{
protected:
    string school;
    double salary;

public:
    void print_info();
    Assistant(string name = 0, string id = 0, string sex = 0, string school = 0, double salary = 0);
};
#endif