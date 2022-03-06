#include <iostream>
using namespace std;
int main()
{
    int num[10];
    bool find = false;
    int i, begin = 0, end = 10, need;
    for (i = 0; i < 10; i++)
        cin >> num[i];
    cin >> need;
    do
        if (num[(begin + end) / 2] == need)
        {
            find = true;
            cout << "Found it!";
            break;
        }
        else if (num[(begin + end) / 2] > need)
            end = (begin + end) / 2 - 1;
        else
            begin = (begin + end) / 2 + 1;
    while (begin <= end);
    if (find == false)
        cout << "Not found!";
    return 0;
}