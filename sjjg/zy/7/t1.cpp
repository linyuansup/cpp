#include <iostream>
#include "list_b.h"
using namespace std;
int main()
{
	int len;
	lista l1;
	lista l2;
	cin >> len;
	for (int i = 1; i <= len; i++)
	{
		int num;
		cin >> num;
		l1.append(i, num);
	}
	for (int i = 1; i <= len; i++)
	{
		int num;
		cin >> num;
		l2.append(i, num);
	}
	lista l3;
	for (int i = 1; i <= len; i++)
	{
		int x;
		l1.get_data(i, x);
		l3.append(i, x);
	}
	for (int i = 1; i <= len; i++)
	{
		int x;
		l2.get_data(i, x);
		l3.append(i + len, x);
	}
	for (int i = 1; i < len * 2; i++)
	{
		int min;
		l3.get_data(i, min);
		for (int j = i + 1; j <= len * 2; j++)
		{
			int x;
			l3.get_data(j, x);
			if (min > x)
			{
				l3.append(i, x);
				l3.pop(j + 1);
				min = x;
			}
		}
	}
	for (int i = 1; i <= len * 2; i++)
	{
		int x;
		l3.get_data(i, x);
		cout << x << " ";
	}
	return 0;
}