/*
 * @Author: 李天阳_linyuansup
 * @Date: 2021-10-19 20:14:22
 * @LastEditors: 李天阳_linyuansup
 * @LastEditTime: 2021-10-20 16:24:50
 * @FilePath: \cpp\sy1t3.cpp
 */

#include <iostream>
using namespace std;
int main()
{
    int month, room;
    double money;
    cout << "Enter the month and room you want:";
    cin >> month >> room;
    if (month >= 7 && month <= 9)
    {
        if (room >= 20)
            money = 278.6;
        else
            money = 338.3;
    }
    else
    {
        if (room >= 20)
            money = 199;
        else
            money = 278.6;
    }
    cout << "the money is " << money * room << endl;
    return 0;
}