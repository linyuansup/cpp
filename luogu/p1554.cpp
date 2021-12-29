#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m, n;
    cin >> m >> n;
    int a[10] = {0};
    for (m; m <= n; m++)
    {
        int temp = m;
        while (temp)
        {
            a[temp % 10]++;
            temp /= 10;
        }
    }
    cout << a[0] << " " << a[1] << " " << a[2] << " " << a[3] << " " << a[4] << " " << a[5] << " " << a[6] << " " << a[7] << " " << a[8] << " " << a[9];
    return 0;
}