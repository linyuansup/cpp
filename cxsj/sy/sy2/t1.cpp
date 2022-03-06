/*
 * @Author: 李天阳_linyuansup
 * @Date: 2021-11-03 16:11:20
 * @LastEditors: 李天阳_linyuansup
 * @LastEditTime: 2021-11-03 20:15:01
 * @Description: file content
 * @FilePath: /cpp/sy2/t1.cpp
 */

#include <iostream>
using namespace std;
int main()
{
    int num, wei, temp, part;
    long long dou;
    for (num = 0; num <= 1000; num++)
    {
        wei = 10;
        dou = num * num;
        temp = num;
        while (temp / 10 != 0)
        {
            temp /= 10;
            wei *= 10;
        }
        part = dou % wei;
        if (part == num)
            cout << num << endl;
    }
    return 0;
}