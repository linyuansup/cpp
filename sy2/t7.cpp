/*
 * @Author: 李天阳_linyuansup
 * @Date: 2021-11-03 16:17:11
 * @LastEditors: 李天阳_linyuansup
 * @LastEditTime: 2021-11-03 17:17:17
 * @Description: file content
 * @FilePath: /cpp/sy2/t7.cpp
 */

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, n, num = 0, plu = 0, i, j;
    cin >> a >> n;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= i; j++)
            plu += a * pow(10, j - 1);
        num += plu;
        plu = 0;
    }
    cout << num << endl;
    return 0;
}