/*
 * @Author: 李天阳_linyuansup
 * @Date: 2021-10-19 20:03:17
 * @LastEditors: 李天阳_linyuansup
 * @LastEditTime: 2021-10-19 20:21:19
 * @FilePath: \cpp\sy1t2.cpp
 */

#include <iostream>
using namespace std;
int main()
{
    int number,i;
    int a[4] = {0,0,0,0};
    bool condition = true;
    cout<<"input number:";
    cin >> number;
    a[3] = number / 1 % 10;
    a[2] = number / 10 % 10;
    a[1] = number / 100 % 10;
    a[0] = number / 1000 % 10;
    for (i = 0; i <= 2; i++){
        if (a[i] <=a[i + 1]){
            condition = false;
        }
    }
    if (condition)
    cout<<"it is jiangxushu";
    else
    cout<<"it isn't jiangxushu";
    return 0;
}