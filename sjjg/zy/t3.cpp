#include <bits/stdc++.h>
using namespace std;
void bucketSort(int arr[], unsigned long int len)
{
    int bucketLen = RAND_MAX + 1;
    unsigned long int bucket[bucketLen];
    for (int i = 0; i < bucketLen; i++)
        bucket[i] = 0;
    int index = 0;
    for (unsigned long int i = 0; i < len; i++)
    {
        index = arr[i];
        bucket[index] += 1;
    }
    unsigned long int start = 0;
    for (int i = 0; i < bucketLen; i++)
    {
        for (unsigned long int j = start; j < start + bucket[i]; j++)
            arr[j] = i;
        start += bucket[i];
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
        bucketSort(p, i);
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