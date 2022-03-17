#include <iostream>
#include "queue.h"
using namespace std;
void solve(int n)
{
	int a, b;
	queue<int> q;
	q.append(0);
	q.append(1);
	q.append(0);
	for (int i = 1; i <= n;)
	{
		q.get_front(a);
		q.serve();
		q.get_front(b);
		cout << a + b << " ";
		q.append(a + b);
		a
		if (b == 0)
		{
			q.append(0);
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