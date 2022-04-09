#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a, b, l;
	cin >> a >> b >> l;
	if (b == l)
		cout << "fill B" << endl;
	else if (a == l)
		cout << "fill A" << endl << "A to B" << endl;
	else
	{
		int x = 0, y = 0;
		if (a < l)
			while (true)
			{
				if (y == 0)
				{
					y = b;
					cout << "fill B" << endl;
				}
				if (y > a - x)
				{
					y -= a - x;
					x = a;
					cout << "B to A" << endl;
				}
				else
				{
					x += y;
					y = 0;
					cout << "B to A" << endl;
				}
				if (y == l)
					break;
				if (a == x)
				{
					x = 0;
					cout << "pour A" << endl;
				}
			}
		else
			while (true)
			{
				if (x == 0)
				{
					x = a;
					cout << "fill A" << endl;
				}
				if (x > b - y)
				{
					x -= b - y;
					y = b;
					cout << "A to B" << endl;
				}
				else
				{
					y += x;
					x = 0;
					cout << "A to B" << endl;
				}
				if (y == l)
					break;
				if (y == b)
				{
					y = 0;
					cout << "pour B" << endl;
				}
			}
		cout << "success";
	}
	return 0;
}