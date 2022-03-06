#include <iostream>
using namespace std;
double max(double *data, int n)
{
    int maxp = 0;
    for (int pos = 1; pos < n; pos++)
        if (data[maxp] < data[pos])
            maxp = pos;
    return data[maxp];
}
int main()
{
    int n;
    cin >> n;
    double *data = new double[n];
    for (int i = 0; i < n; i++)
        cin >> data[i];
    cout << max(data, n) << endl;
    delete[] data;
    data = NULL;
    return 0;
}