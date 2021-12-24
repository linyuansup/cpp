#include "Assistant.h"
Assistant::Assistant(string name, string id, string sex, string school, double salary) : Person(name, id, sex)
{
    this->salary = salary;
    this->school = school;
}
void Assistant::print_info()
{
    Person::print_info();
    cout << "School: " << school << endl
         << "Salary: " << salary << endl;
}