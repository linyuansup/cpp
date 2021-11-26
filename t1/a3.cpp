#include <iostream>
using namespace std;
int main()
{
    char data[256], ch2[256];
    int j = 0, num = 1, out = 0, wei = 0;
    gets(data);
    for (int i = 0; data[i]; i++)
        if (data[i] >= '0' && data[i] <= '9')
        {
            ch2[j] = data[i];
            j++;
        }
    ch2[j] = '\0';
    for (int i = 0; ch2[i]; i++)
    {
        num *= 10;
        wei++;
    }
    for (int i = 0; i < wei; i++, num /= 10)
        out += (ch2[i] - '0') * num;
    out /= 10;
    cout << out << endl;
    return 0;
}