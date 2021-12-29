#include <iostream>
using namespace std;
int main()
{
    int k, money = 0, p = 0;
    cin >> k;
    for (int i = 1;; i++)
        for (int j = 1; j <= i; j++)
            if (p >= k)
            {
                cout << money;
                return 0;
            }
            else
            {
                money += i;
                p++;
            }
    return 0;
}