/*
 * @Author: 李天阳_linyuansup
 * @Date: 2021-10-19 20:42:10
 * @LastEditors: 李天阳_linyuansup
 * @LastEditTime: 2021-10-19 20:48:46
 * @FilePath: \cpp\sy1t6.cpp
 */

#include <iostream>
using namespace std;
int main()
{
    int month, year;
    cout << "please enter month and year:";
    cin >> month >> year;
    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
    {
        cout << "31" << endl;
        break;
    }
    case 4:
    case 6:
    case 9:
    case 11:
    {
        cout << "30" << endl;
        break;
    }
    case 2:
    {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 4 == 0 && year % 400 == 0))
        {
            cout << "29" << endl;
            break;
        }
        else
        {
            cout << "28" << endl;
            break;
        }
    }
    }
    return 0;
}