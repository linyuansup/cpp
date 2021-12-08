#include "Student.h"
using namespace std;
Student::Student(const char *p1, const char *p2, double _math, double _phy, double _eng)
{
    if (p1)
        for (int i = 0; i < 10; i++)
            id[i] = p1[i];
    if (p2)
        for (int i = 0; i < 10; i++)
            name[i] = p2[i];
    math = _math;
    physics = _phy;
    english = _eng;
}
void Student::set_info(const char *p1, const char *p2, double _math, double _phy, double _eng)
{
    int i = 0;
    for (i = 0; i < 10; i++)
        id[i] = p1[i];
    id[i] = '\0';
    for (i = 0; i < 10; i++)
        name[i] = p2[i];
    name[i] = '\0';
    math = _math;
    physics = _phy;
    english = _eng;
    return;
}
double Student::total()
{
    return math + physics + english;
}
char *Student::get_id()
{
    return id;
}
void Student::show_info()
{
    cout << "ID: " << id << endl;
    cout << "姓名: " << name << endl;
    cout << "数学成绩: " << math << endl;
    cout << "物理成绩: " << physics << endl;
    cout << "英语成绩: " << english << endl;
    return;
}