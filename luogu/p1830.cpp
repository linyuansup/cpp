#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    int num[n][m] = {0};
    int last[n][m] = {0};
    int pos[y][2];
    for (int i = 0; i < x; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int j = x1 - 1; j < x2; j++)
            for (int k = y1 - 1; k < y2; k++)
            {
                num[j][k]++;
                last[j][k] = i + 1;
            }
    }
    for (int i = 0; i < y; i++)
    {
        cin >> pos[i][0] >> pos[i][1];
        pos[i][0]--;
        pos[i][1]--;
    }
    for (int i = 0; i < y; i++)
        if (num[pos[i][0]][pos[i][1]] == 0)
            cout << "N" << endl;
        else
            cout << "Y " << num[pos[i][0]][pos[i][1]] << " " << last[pos[i][0]][pos[i][1]] << endl;
    return 0;
}