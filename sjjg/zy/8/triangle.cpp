#include <iostream>
#include <queue>
using namespace std;
void solve(int n)
{
	cout << 1 << endl;
	queue<int> q;
	q.push(0);
	q.push(1);
	q.push(0);
	for (int i = 1; i < n;)
	{
		int a = q.front();
		q.pop();
		int b = q.front();
		cout << a + b << " ";
		q.push(a + b);
		if (b == 0)
		{
			q.push(0);
			i++;
			cout << endl;
		}
	}
}
int main()
{
	int n;
	cin >> n;
	solve(n);
	return 0;
}