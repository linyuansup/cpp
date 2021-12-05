/*
 * @Author: 李天阳_linyuansup
 * @Date: 2021-11-03 16:17:07
 * @LastEditors: 李天阳_linyuansup
 * @LastEditTime: 2021-11-03 17:08:24
 * @Description: file content
 * @FilePath: /cpp/sy2/t6.cpp
 */

#include <iostream>
using namespace std;
int main()
{
    int num, i;
    cin >> num;
    for (i = 2; i <= num; i++)
    {
        if (num % i == 0)
        {
            cout << i << " ";
            num /= i;
            i--;
        }
    }
    return 0;
}