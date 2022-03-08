#include <bits/stdc++.h>
using namespace std;
// jyc
int counter;
void jyc_pao_sort(int *array, int n)
{
    for (int i = n - 1; i >= 0; i--)
        for (int j = n - 1; j >= n - i; j--)
            if (array[j] < array[j - 1])
            {
                int temp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = temp;
            }
}
void jyc_xuan_sort(int *array, int n)
{
    for (int i = 0; i < n; i++)
    {
        int min_index = i;
        for (int j = 0; j < n - i; j++)
            if (array[i + j] < array[min_index])
                min_index = i + j;
        int temp = array[min_index];
        array[min_index] = array[i];
        array[i] = temp;
    }
}
void jyc_he_bing(int nums[], int lmin, int rmin, int rmax)
{
    int temp;
    while (lmin <= rmin - 1 && rmin <= rmax)
    {
        if (lmin == rmin)
            return;
        if (nums[lmin] < nums[rmin])
            lmin++;
        else
        {
            temp = nums[rmin];
            for (int i = rmin; i >= lmin; i--)
                nums[i] = nums[i - 1];
            nums[lmin] = temp;
            rmin++;
        }
    }
}
void jyc_gui_bing(int nums[], int left, int right)
{
    if (left == right)
        return;
    int q = (left + right) / 2;
    jyc_gui_bing(nums, left, q);
    jyc_gui_bing(nums, q + 1, right);
    jyc_he_bing(nums, left, q + 1, right);
}
// lyc
void lyc_print(int *a, int n)
{
    for (int i = 0, j = 0; i < n; i++)
    {
        cout << a[i] << " ";
        j++;
    }
    cout << endl;
    return;
}
int *lyc_base(int *a, int *f, int *e, int mid)
{
    if (f == e)
    {
        *f = mid;
        counter++;
        return f;
    }
    int *m, *of = f, *oe = e;
    for (; *e >= mid && e != f && e > of; e--)
        ;
    *f = *e;
    for (; *f <= mid && f != e && f < oe; f++)
        ;
    *e = *f;
    m = lyc_base(a, f, e, mid);
    return m;
}
void lyc_process(int *a, int *f, int *e, int *mid)
{
    for (int *i = f; i != e; i++)
    {
        if (*i > *(i + 1))
            break;
        else if (i + 1 == e)
            return;
    }
    if (f == e)
        return;
    if (f + 1 == e)
    {
        if (*f > *e)
        {
            int temp = *f;
            *f = *e;
            *e = temp;
        }
        return;
    }
    int *m = NULL;
    if (f != mid - 1 && f != mid)
    {
        m = lyc_base(a, f, mid - 1, *f);
        for (int *i = f; i < (mid - 1); i++)
            if (*i > *(i + 1))
            {
                lyc_process(a, f, mid - 1, m);
                break;
            }
    }
    if (e != mid + 1 && e != mid)
    {
        m = lyc_base(a, mid + 1, e, *(mid + 1));
        for (int *i = mid + 1; i < e; i++)
            if (*i > *(i + 1))
            {
                lyc_process(a, mid + 1, e, m);
                break;
            }
    }
    return;
}
// qc
void qc_maopao(int a[], int size)
{
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - 1; j++)
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
}
void qc_xuanze(int a[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min = a[i];
        int flag = i;
        for (int j = i; j < size; j++)
            if (a[j] < min)
            {
                min = a[j];
                flag = j;
            }
        int temp = a[i];
        a[i] = a[flag];
        a[flag] = temp;
    }
}
void qc_merg(int a[], int lmin, int rmin, int rmax)
{
    int temp;
    while (lmin <= rmin - 1 and rmin <= rmax)
    {
        if (lmin == rmin)
            return;
        if (a[lmin] <= a[rmin])
            lmin++;
        else
        {
            temp = a[rmin];
            for (int k = rmin; k >= lmin; k--)
                a[k] = a[k - 1];
            a[lmin++] = temp;
            rmin++;
        }
    }
}
void qc_guibing(int a[], int left, int right)
{
    if (left == right)
        return;
    int q = (left + right) / 2;
    qc_guibing(a, left, q);
    qc_guibing(a, q + 1, right);
    qc_merg(a, left, q + 1, right);
}
int main()
{
    unsigned seed = time(0);
    srand(seed);
    clock_t start, end;
    const unsigned long int i = 100000;
    cout << "Generating random array for " << i << "..." << endl;
    start = clock();
    int *p = new int[i];
    for (unsigned long int j = 0; j < i; j++)
        p[j] = rand();
    int *pbacked = new int[i];
    for (unsigned long int j = 0; j < i; j++)
        pbacked[j] = p[j];
    end = clock();
    cout << "Generate fininshed in " << double(end - start) / CLOCKS_PER_SEC << " seconds." << endl;
    cout << "Sorting... jyc pao" << endl;
    start = clock();
    jyc_pao_sort(p, i);
    end = clock();
    cout << "Sort fininshed in " << double(end - start) / CLOCKS_PER_SEC << " seconds." << endl;
    cout << "Sorting... jyc xuan" << endl;
    for (unsigned long int j = 0; j < i; j++)
        p[j] = pbacked[j];
    start = clock();
    jyc_xuan_sort(p, i);
    end = clock();
    cout << "Sort fininshed in " << double(end - start) / CLOCKS_PER_SEC << " seconds." << endl;
    cout << "Sorting... jyc gui bing" << endl;
    for (unsigned long int j = 0; j < i; j++)
        p[j] = pbacked[j];
    start = clock();
    jyc_gui_bing(p, 0, i - 1);
    end = clock();
    cout << "Sort fininshed in " << double(end - start) / CLOCKS_PER_SEC << " seconds." << endl;
    cout << "Sorting... lyc process" << endl;
    for (unsigned long int j = 0; j < i; j++)
        p[j] = pbacked[j];
    start = clock();
    int *mid;
    mid = lyc_base(p, p, &p[i - 1], p[0]);
    lyc_process(p, &p[0], &p[i - 1], mid);
    end = clock();
    cout << "Sort fininshed in " << double(end - start) / CLOCKS_PER_SEC << " seconds." << endl;
    cout << "Sorting... qc maopao" << endl;
    for (unsigned long int j = 0; j < i; j++)
        p[j] = pbacked[j];
    start = clock();
    qc_maopao(p, i);
    end = clock();
    cout << "Sort fininshed in " << double(end - start) / CLOCKS_PER_SEC << " seconds." << endl;
    cout << "Sorting... qc xuanze" << endl;
    for (unsigned long int j = 0; j < i; j++)
        p[j] = pbacked[j];
    start = clock();
    qc_xuanze(p, i);
    end = clock();
    cout << "Sort fininshed in " << double(end - start) / CLOCKS_PER_SEC << " seconds." << endl;
    cout << "Sorting... qc gui bing" << endl;
    for (unsigned long int j = 0; j < i; j++)
        p[j] = pbacked[j];
    start = clock();
    qc_guibing(p, 0, i - 1);
    end = clock();
    cout << "Sort fininshed in " << double(end - start) / CLOCKS_PER_SEC << " seconds." << endl;
    delete[] p;
    return 0;
}