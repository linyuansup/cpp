#include <iostream>
using namespace std;
void extreme_pos(int *array, int n, int *pos)
{
    pos[0] = pos[1] = 0;
    for (int i = 1; i < n; i++)
    {
        if (pos[0] > array[i])
            pos[0] = i;
        if (pos[1] < array[i])
            pos[1] = i;
    }
}
int main()
{
    int n;
    cin >> n;
    int *array = new int[n];
    int pos[2] = {};
    for (int i = 0; i < n; i++)
        cin >> array[i];
    extreme_pos(array, n, pos);
    for (int i = 0; i < 2; i++)
        cout << pos[i] << " ";
    delete[] array;
    array = NULL;
    return 0;
}