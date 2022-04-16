#include <bits/stdc++.h>
using namespace std;
int solve(int n)
{
	int ret = 1, num = 1;
	if (n != 1 && n != 2)
		for (int i = 0; i < n - 2; i++)
		{
			int temp = ret;
			ret += num;
			num = temp;
		}
	return ret;
}
int main()
{
	int n;
	cin >> n;
	cout << solve(n);
	return 0;
}