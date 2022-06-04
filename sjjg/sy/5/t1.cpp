#include <iostream>
#include "list.h"
using namespace std;
list operator-(list l1, list l2)
{
	int x, y, j;
	for (int i = 1; i <= l2.length(); i++)
	{
		l2.get_data(i, x);
		bool same = false;
		for (j = 1; j <= l1.length(); j++)
		{
			l1.get_data(j, y);
			if (x == y)
			{
				same = true;
				break;
			}
		}
		if (same)
			l1.pop(j);
	}
	return l1;
}
list u(list l1, list l2)
{
	int x, y, len;
	len = l1.length();
	for (int i = 1; i <= l2.length(); i++)
	{
		l2.get_data(i, x);
		bool same = false;
		for (int j = 1; j <= len; j++)
		{
			l1.get_data(j, y);
			if (x == y)
			{
				same = true;
				break;
			}
		}
		if (!same)
			l1.append(len + 1, x);
	}
	return l1;
}
list a(list l1, list l2)
{
	list ret;
	int x, y;
	for (int i = 1; i <= l1.length(); i++)
	{
		l1.get_data(i, x);
		for (int j = 1; j <= l2.length(); j++)
		{
			l2.get_data(j, y);
			if (x == y)
			{
				ret.append(1, y);
				break;
			}
		}
	}
	return ret;
}
void show(list a)
{
	int x;
	for (int i = 1; i <= a.length(); i++)
	{
		a.get_data(i, x);
		cout << x << " ";
	}
	cout << endl;
}
int main()
{
	list l1, l2, l3;
	int len1, len2, x;
	cin >> len1 >> len2;
	for (int i = 1; i <= len1; i++)
	{
		cin >> x;
		l1.append(i, x);
	}
	for (int i = 1; i <= len2; i++)
	{
		cin >> x;
		l2.append(i, x);
	}
	l3 = u(l1, l2);
	show(l3);
	l3 = a(l1, l2);
	show(l3);
	l3 = l1 - l2;
	show(l3);
	return 0;
}