/*
 * @Author: 李天阳_linyuansup
 * @Date: 2021-11-02 21:17:44
 * @LastEditors: 李天阳_linyuansup
 * @LastEditTime: 2021-11-03 17:08:57
 * @Description: file content
 * @FilePath: /cpp/sy2/t3.cpp
 */

#include <iostream>
using namespace std;
int main()
{
    int num, i;
    int plus = 0;
    for (num = 3; num <= 1000; num++)
    {
        for (i = 1; i < num; i++)
            if (num % i == 0)
                plus += i;
        if (num == plus)
            cout << num << endl;
        plus = 0;
    }
    return 0;
}