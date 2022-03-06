#include "Student.h"
Student::Student(string name, string id, string sex, string major, string grade) : Person(name, id, sex)
{
    this->major = major;
    this->grade = grade;
}
string Student::get_major()
{
    return major;
}
string Student::get_grade()
{
    return grade;
}
void Student::print_info()
{
    Person::print_info();
    cout << "Major: " << major << endl
         << "Grade: " << grade << endl;
}