#include <bits/stdc++.h>
using namespace std;
int main()
{
    int l, r, sum = 0;
    cin >> l >> r;
    for (l; l <= r; l++)
    {
        int temp = l;
        while (temp)
        {
            if (temp % 10 == 2)
                sum++;
            temp /= 10;
        }
    }
    cout << sum;
    return 0;
}