#include <bits/stdc++.h>
using namespace std;
int solve(int n)
{
	stack<int> s1, s2;
	int ret = 0;
L0:
	if (n == 1 || n == 2)
		ret++;
	else
	{
		s1.push(n);
		n--;
		goto L0;
	L1:
		s2.push(n);
		n -= 2;
		goto L0;
	}
L2:
	while (!s1.empty())
	{
		n = s1.top();
		s1.pop();
		goto L1;
	}
	while (!s2.empty())
	{
		s2.pop();
		goto L2;
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