#include <iostream>
using namespace std;
int main()
{
    int base[7] = {100, 50, 20, 10, 5, 2, 1};
    int count[7] = {};
    int money;
    cin >> money;
    for (int i = 0; i < 7; i++)
    {
        count[i] = money / base[i];
        money %= base[i];
    }
    for (int i = 0; i < 7; i++)
        cout << base[i] << " : " << count[i] << endl;
    return 0;
}