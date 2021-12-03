#include <iostream>
using namespace std;
int main()
{
    int l, m, num = 0;
    cin >> l >> m;
    int *road = new int[l + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        for (int j = u; j <= v; j++)
            road[j] = 1;
    }
    for (int i = 0; i < l + 1; i++)
        if (road[i] != 1)
            num++;
    cout << num << endl;
    return 0;
}