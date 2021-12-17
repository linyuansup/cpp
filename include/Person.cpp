#include "Person.h"
using namespace std;
Person::Person(string name, string id, string sex)
{
    this->name = name;
    this->id = id;
    this->sex = sex;
}
void Person::print_info()
{
    cout << "Name: " << name << endl
         << "Id: " << id << endl
         << "Sex: " << sex << endl;
}