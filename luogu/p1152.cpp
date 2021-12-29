#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int *p = new int[n];
    int *q = new int[n - 1];
    for (int i = 0; i < n; i++)
        cin >> p[i];
    if (n == 1)
    {
        cout << "Jolly";
        return 0;
    }
    for (int i = 0; i < n - 1; i++)
        q[i] = abs(p[i + 1] - p[i]);
    sort(q, q + n - 1);
    for (int i = 0; i < n - 1; i++)
        if (q[i] != i + 1)
        {
            cout << "Not jolly";
            return 0;
        }
    cout << "Jolly";
    return 0;
}