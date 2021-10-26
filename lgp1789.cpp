/*
 * @Author: 李天阳_linyuansup
 * @Date: 2021-10-26 08:29:06
 * @LastEditors: 李天阳_linyuansup
 * @LastEditTime: 2021-10-26 09:20:56
 * @Description: file content
 * @FilePath: /cpp/lgp1789.cpp
 */

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, k, xp, yp, i, map[103][103], j,h, sum = 0;
    memset(map, 0, sizeof(map));
    cin >> n >> m >> k;
    for (h = 1; h <= m; h++)
    {
        cin >> xp >> yp;
        xp += 2;
        yp += 2;
        for (i = xp - 2; i <= xp + 2; i++)
            map[i][yp] = 1;
        for (i = yp - 2; i <= yp + 2; i++)
            map[xp][i] = 1;
        map[xp - 1][yp - 1] = 1;
        map[xp - 1][yp + 1] = 1;
        map[xp + 1][yp - 1] = 1;
        map[xp + 1][yp + 1] = 1;
    }
    if (k != 0)
    {
        for (h = 1; h <= k; h++)
        {
            cin >> xp >> yp;
            xp += 2;
            yp += 2;
            for (i = xp - 2; i <= xp + 2; i++)
            {
                for (j = yp - 2; j <= yp + 2; j++)
                    map[i][j] = 1;
            }
        }
    }
    for (i = 3; i <= n + 2; i++)
    {
        for (j = 3; j <= n + 2; j++)
        {
            if (map[i][j] == 0)
                sum += 1;
        }
    }
    cout << sum;
    return 0;
}