#include "stack.h"
#include <iostream>
using namespace std;
int main()
{
	Stack<char> num;
	e_code err;
	for (char i = 97; i <= 101; i++)
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
	for (char i = 100; i <= 102; i++)
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
	char x;
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