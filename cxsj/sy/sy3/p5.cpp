#include <iostream>
using namespace std;
int main()
{
    char a[256];
    gets(a);
    int i = 0, num[26] = {};
    for (i = 0; a[i]; i++)
    {
        if (a[i] >= 'A' && a[i] <= 'Z')
            a[i] = a[i] + 32;
        num[a[i] - 'a']++;
    }
    for (i = 0; i < 26; i++)
        if (num[i] != 0)
            cout << char(i + 'a') << " " << num[i] << endl;
    return 0;
}