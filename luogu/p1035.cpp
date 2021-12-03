#include <iostream>
using namespace std;
int main()
{
    int n, k;
    double sn = .0;
    cin >> k;
    for (n = 1;; n++)
    {
        sn += 1.0 / n;
        if (sn >= k)
        {
            cout << n << endl;
            break;
        }
    }
    return 0;
}