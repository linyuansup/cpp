/*
 * @Author: 李天阳_linyuansup
 * @Date: 2021-11-03 16:17:00
 * @LastEditors: 李天阳_linyuansup
 * @LastEditTime: 2021-11-03 20:18:38
 * @Description: file content
 * @FilePath: /cpp/sy2/t5.cpp
 */

#include <iostream>
using namespace std;
int main()
{
    int num;
    cin >> num;
    while (num / 10 != 0)
    {
        cout << num % 10;
        num /= 10;
    }
    cout << num << endl;
    return 0;
}