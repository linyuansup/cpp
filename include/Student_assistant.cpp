#include "Student_assistant.h"
Student_assistant::Student_assistant(string name, string id, string sex, string school, double salary, string major, string grade) : Person(name, id, sex), Student(name, id, sex, major, grade), Assistant(name, id, sex, school, salary) {}
void Student_assistant::print_info()
{
    Student::print_info();
    cout << "School: " << school << endl
         << "Salary: " << salary << endl;
}