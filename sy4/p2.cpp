#include <iostream>
using namespace std;
int digitR(int num, int pos)
{
    while (pos > 1)
    {
        num /= 10;
        pos--;
    }
    return num % 10;
}
int main()
{
    int num, pos;
    cin >> num >> pos;
    cout << digitR(num, pos) << endl;
    return 0;
}