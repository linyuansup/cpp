#include <iostream>
using namespace std;
int main()
{
    int i, wei = 1, k = 1, n, num;
    char ch[256] = {};
    cin >> num;
    int temp = num;
    while (temp / 10)
    {
        wei *= 10;
        k++;
        temp /= 10;
    }
    for (i = 0; i < k; i++)
    {
        ch[i] = num / wei + 48;
        num = num - num / wei * wei;
        wei = wei / 10;
    }
    ch[i] = '\0';
    cout << ch << endl;
    return 0;
}
