#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED
#include <iostream>
using namespace std;
class Person
{
protected:
    string name, id, sex;

public:
    Person(string name = 0, string id = 0, string sex = 0);
    void print_info();
};
#endif