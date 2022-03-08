#include <bits/stdc++.h>
using namespace std;
inline int partiton(int a[], int low, int high)
{
    int pivot = a[low];
    while (low < high)
    {
        while (low < high && a[high] >= pivot)
            --high;
        a[low] = a[high];
        while (low < high && a[low] <= pivot)
            ++low;
        a[high] = a[low];
    }
    a[low] = pivot;
    return low;
}
inline void quickSort(int a[], int left, int right)
{
    stack<int> s;
    if (left < right)
    {
        int boundary = partiton(a, left, right);
        if (boundary - 1 > left)
        {
            s.push(left);
            s.push(boundary - 1);
        }
        if (boundary + 1 < right)
        {
            s.push(boundary + 1);
            s.push(right);
        }
        while (!s.empty())
        {
            int r = s.top();
            s.pop();
            int l = s.top();
            s.pop();
            boundary = partiton(a, l, r);
            if (boundary - 1 > l)
            {
                s.push(l);
                s.push(boundary - 1);
            }
            if (boundary + 1 < r)
            {
                s.push(boundary + 1);
                s.push(r);
            }
        }
    }
}
int main()
{
    // freopen("out.txt", "w", stdout);
    unsigned seed = time(0);
    srand(seed);
    clock_t start, end;
    for (unsigned long int i = 200;; i += 200000000)
    {
        i = 500000000;
        cout << "Generating random array for " << i << "..." << endl;
        start = clock();
        int *p = new int[i];
        for (unsigned long int j = 0; j < i; j++)
            p[j] = rand();
        end = clock();
        cout << "Generate fininshed in " << double(end - start) / CLOCKS_PER_SEC << " seconds." << endl;
        cout << "Sorting.." << endl;
        start = clock();
        quickSort(p, 0, i - 1);
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
        return 0;
    }
    return 0;
}