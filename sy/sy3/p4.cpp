#include <iostream>
using namespace std;
int main()
{
    int tri[10][10] = {};
    int i, j;
    tri[1][1] = tri[2][1] = tri[2][2] = 1;
    for (i = 3; i <= 9; i++)
        for (j = 1; j <= i; j++)
            tri[i][j] = tri[i - 1][j] + tri[i - 1][j - 1];
    for (i = 1; i <= 9; i++)
    {
        for (j = 1; j <= i; j++)
            cout << tri[i][j] << " ";
        cout << endl;
    }
    return 0;
}