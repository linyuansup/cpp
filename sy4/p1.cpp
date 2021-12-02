#include <iostream>
using namespace std;
bool isOddDigit(int n)
{
    while (n > 0)
    {
        if (n % 10 % 2 == 0)
            return false;
        n /= 10;
    }
    return true;
}
int main()
{
    int n;
    cin >> n;
    if (isOddDigit(n))
        cout << "true";
    else
        cout << "false";
    return 0;
}