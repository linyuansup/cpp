#include <iostream>
using namespace std;
int main()
{
    int input, i, j = 10, data[10];
    for (i = 0; i < 9; i++)
        cin >> data[i];
    cin >> input;
    for (i = 0; i < 10; i++)
        if (input < data[i])
        {
            j = i;
            break;
        }
    for (i = 10; i >= j; i--)
        data[i] = data[i - 1];
    data[j] = input;
    for (i = 0; i < 10; i++)
        cout << data[i] << " ";
    return 0;
}