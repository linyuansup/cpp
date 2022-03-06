/*
 * @Author: 李天阳_linyuansup
 * @Date: 2021-11-03 16:17:15
 * @LastEditors: 李天阳_linyuansup
 * @LastEditTime: 2021-11-03 19:12:24
 * @Description: file content
 * @FilePath: /cpp/sy2/t8.cpp
 */

#include <iostream>
using namespace std;
int main()
{
    int i, j, num;
    for (i = 6; i >= 1; i--)
    {
        for (j = 6; j > i; j--)
            cout << "  ";
        for (num = 1; num <= i; num++)
            cout << num << " ";
        cout << endl;
    }
    return 0;
}