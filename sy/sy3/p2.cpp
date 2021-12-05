#include <iostream>
using namespace std;
int main()
{
    int i, j, min, temp;
    int num[10];
    for (i = 0; i < 10; i++)
        cin >> num[i];
    for (i = 0; i < 10; i++)
    {
        min = i;
        for (j = i + 1; j < 10; j++)
            if (num[j] < num[min])
                min = j;
        if (min != i)
        {
            temp = num[i];
            num[i] = num[min];
            num[min] = temp;
        }
    }
    for (i = 0; i < 10; i++)
        cout << num[i] << " ";
    return 0;
}