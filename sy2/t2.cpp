/*
 * @Author: 李天阳_linyuansup
 * @Date: 2021-11-03 16:16:40
 * @LastEditors: 李天阳_linyuansup
 * @LastEditTime: 2021-11-03 20:09:03
 * @Description: file content
 * @FilePath: /cpp/sy2/t2.cpp
 */

#include <iostream>
using namespace std;
int main()
{
    long long int temp_a, temp_b, num, change;
    for (num = 8;; num += 10)
    {
        change = 8;
        temp_a = temp_b = num;
        while (temp_a / 10 != 0)
        {
            temp_a /= 10;
            change *= 10;
        }
        temp_b /= 10;
        if (temp_b + change == num * 4)
        {
            cout << num << endl;
            break;
        }
    }
    return 0;
}