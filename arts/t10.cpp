#include <iostream>
#include <string>
using namespace std;
int main()
{
	string a, b;
	cin >> a >> b;
	int f[100][100];
	for (int i = 0; i <= b.length(); i++)
		f[i][0] = i;
	for (int j = 0; j <= a.length(); j++)
		f[0][j] = j;
	for (int i = 1; i <= b.length(); i++)
		for (int j = 1; j <= a.length(); j++)
			if (a[i] == b[j])
				f[i][j] = f[i - 1][j - 1];
			else
				f[i][j] = min(min(f[i - 1][j] + 1, f[i][j - 1] + 1), f[i - 1][j - 1] + 1);
	cout << f[b.length()][a.length()] << endl;
	return 0;
}
