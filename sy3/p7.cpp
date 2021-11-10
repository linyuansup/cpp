#include <iostream>
using namespace std;
int main()
{
    char ch1[256], ch2[256], ch3[256];
    int pos;
    gets(ch1);
    gets(ch2);
    cin >> pos;
    for (int i = 0; i < pos; i++)
        ch3[i] = ch1[i];
    int temp = pos;
    for (int i = 0; ch3[i] != '\0'; i++, temp++)
        ch3[temp] = ch2[i];
    for (int i = pos; ch1[i] != '\0'; i++, temp++)
        ch3[temp - 3] = ch1[i];
    for (int i = 0; ch3[i] != '\0'; i++)
        ch1[i] = ch3[i];
    cout << ch1 << endl;
    return 0;
}