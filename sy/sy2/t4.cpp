/*
 * @Author: 李天阳_linyuansup
 * @Date: 2021-11-03 16:16:49
 * @LastEditors: 李天阳_linyuansup
 * @LastEditTime: 2021-11-03 17:00:15
 * @Description: file content
 * @FilePath: /cpp/sy2/t4.cpp
 */

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i, n;
    int plu;
    double cos = 1., x;
    cin >> x;
    x = x * 3.1415926 / 180;
    for (i = 2; i <= 20; i += 2)
    {
        plu = i;
        for (n = i - 1; n; n--)
            plu *= n;
        if (i % 4)
            cos -= pow(x, i) / plu;
        else
            cos += pow(x, i) / plu;
    }
    cout << cos << endl;
    return 0;
}