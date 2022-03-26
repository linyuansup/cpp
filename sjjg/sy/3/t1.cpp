#include "queue.h"
#include <iostream>
using namespace std;
int main()
{
	queue<int> num;
	e_code err;
	for (int i = 1; i <= 5; i++)
	{
		err = num.append(i);
		if (err != success)
		{
			cout << "error" << endl;
			return 1;
		}
	}
	for (int i = 0; i < 2; i++)
	{
		err = num.serve();
		if (err != success)
		{
			cout << "error" << endl;
			return 1;
		}
	}
	for (int i = 4; i <= 6; i++)
	{
		err = num.append(i);
		if (err != success)
		{
			cout << "error" << endl;
			return 1;
		}
	}
	for (int i = 0; i < 1; i++)
	{
		err = num.serve();
		if (err != success)
		{
			cout << "error" << endl;
			return 1;
		}
	}
	int x;
	err = num.get_front(x);
	if (err == success)
		cout << x << endl;
	else
	{
		cout << "error" << endl;
		return 1;
	}
	return 0;
}