#include <iostream>
using namespace std;
bool isPalindromes(int n)
{
    int wei, temp = n, start;
    for (wei = 0; temp; wei++)
        temp /= 10;
    int *p = new int[wei];
    for (temp = 0; temp < wei; temp++)
    {
        p[temp] = n % 10;
        n /= 10;
    }
    wei--;
    for (start = 0; start <= wei - 1; start++, wei--)
        if (p[start] != p[wei])
        {
            delete[] p;
            p = NULL;
            return false;
        }
    delete[] p;
    p = NULL;
    return true;
}
int main()
{
    int n;
    cin >> n;
    if (isPalindromes(n))
        cout << "true";
    else
        cout << "false";
    return 0;
}