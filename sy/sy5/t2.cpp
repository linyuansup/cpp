#include "Student.h"
using namespace std;
int main()
{
    Student stu[5];
    stu[0].set_info("1294830252", "张三", 50.5, 50, 50);
    stu[1].set_info("2058928510", "李四", 10, 60.5, 70);
    stu[2].set_info("1092859018", "王二麻子", 0.5, 0, 0);
    stu[3].set_info("1859215902", "王五", 100, 100, 99.5);
    stu[4].set_info("3284976275", "名字好难起", 30, 80.5, 70);
    for (int i = 0; i < 5; i++)
        cout << stu[i].total() << endl;
    char id[11];
    cin >> id;
    for (int i = 0; i < 5; i++)
    {
        bool sta = true;
        for (int j = 0; id[j]; j++)
        {
            if (stu[i].get_id()[j] != id[j])
            {
                sta = false;
                break;
            }
        }
        if (sta)
            stu[i].show_info();
    }
    return 0;
}