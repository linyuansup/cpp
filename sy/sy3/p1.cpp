#include <iostream>
using namespace std;
int main()
{
    int num[10];
    double average = 0;
    for (int i = 0; i < 10; i++)
    {
        cin >> num[i];
        average += num[i];
    }
    average = average / 10;
    for (int i = 0; i < 10; i++)
        if (num[i] < average)
            cout << num[i] << " ";
    return 0;
}