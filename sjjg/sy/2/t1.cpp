#include "stack.h"
#include <iostream>
using namespace std;
int main()
{
	Stack<int> num;
	e_code err;
	for (int i = 1; i <= 5; i++)
	{
		err = num.push(i);
		if (err != success)
		{
			cout << "error" << endl;
			return 1;
		}
	}
	for (int i = 0; i < 2; i++)
	{
		err = num.pop();
		if (err != success)
		{
			cout << "error" << endl;
			return 1;
		}
	}
	for (int i = 4; i <= 6; i++)
	{
		err = num.push(i);
		if (err != success)
		{
			cout << "error" << endl;
			return 1;
		}
	}
	for (int i = 0; i < 1; i++)
	{
		err = num.pop();
		if (err != success)
		{
			cout << "error" << endl;
			return 1;
		}
	}
	int x;
	err = num.get_top(x);
	if (err == success)
		cout << x << endl;
	else
	{
		cout << "error" << endl;
		return 1;
	}
	return 0;
}