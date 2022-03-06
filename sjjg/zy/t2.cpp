#include <bits/stdc++.h>
using namespace std;
inline void adjust(int arr[], unsigned long int len, unsigned long int index)
{
    unsigned long int left = 2 * index + 1;
    unsigned long int right = 2 * index + 2;
    unsigned long int maxIdx = index;
    if (left < len && arr[left] > arr[maxIdx])
        maxIdx = left;
    if (right < len && arr[right] > arr[maxIdx])
        maxIdx = right;
    if (maxIdx != index)
    {
        swap(arr[maxIdx], arr[index]);
        adjust(arr, len, maxIdx);
    }
}
inline void heapSort(int arr[], unsigned long int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
        adjust(arr, size, i);
    for (int i = size - 1; i >= 1; i--)
    {
        swap(arr[0], arr[i]);
        adjust(arr, i, 0);
    }
}
int main()
{
    freopen("out.txt", "w", stdout);
    unsigned seed = time(0);
    srand(seed);
    clock_t start, end;
    for (unsigned long int i = 200000000; i <= 1000000000; i += 200000000)
    {
        cout << "Generating random array for " << i << "..." << endl;
        start = clock();
        int *p = new int[i];
        for (unsigned long int j = 0; j < i; j++)
            p[j] = rand();
        end = clock();
        cout << "Generate fininshed in " << double(end - start) / CLOCKS_PER_SEC << " seconds." << endl;
        cout << "Sorting.." << endl;
        start = clock();
        heapSort(p, i);
        end = clock();
        cout << "Sort fininshed in " << double(end - start) / CLOCKS_PER_SEC << " seconds." << endl;
        cout << "Checking.." << endl;
        start = clock();
        for (unsigned long int j = 1; j < i; j++)
            if (p[j] < p[j - 1])
            {
                cout << "Error!" << endl;
                return 0;
            }
        end = clock();
        cout << "Check fininshed in " << double(end - start) / CLOCKS_PER_SEC << " seconds." << endl;
        cout << endl;
        delete[] p;
    }
    return 0;
}