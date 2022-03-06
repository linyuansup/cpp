#include "Student.h"
int main()
{
    Person per("zhangsan", "1234567890", "Man");
    per.print_info();
    cout << endl;
    Student stu("lisi", "9876543210", "Female", "SE", "1");
    stu.print_info();
    return 0;
}