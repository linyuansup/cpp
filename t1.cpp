#include <iostream>
#include "stack.h"
using namespace std;
inline bool judge(char x)
{
	if (x == '+' || x == '-' || x == '*' || x == '/' || x == ')' || x == '#')
		return true;
	return false;
}
inline int calculate(int x, int y, char z)
{
	switch (z)
	{
	case '+':
		return x + y;
	case '-':
		return x - y;
	case '*':
		return x * y;
	case '/':
		return x / y;
	default:
		return 0;
	}
}
inline int priority(char x)
{
	switch (x)
	{
	case '#':
		return 0;
	case '(':
	case ')':
		return 1;
	case '+':
	case '-':
		return 2;
	case '*':
	case '/':
		return 3;
	default:
		return -1;
	}
}
int main()
{
	stack<int> num;
	stack<char> ope;
	string s;
	cin >> s;
	int temp = 0;
	ope.push(s[0]);
	for (int i = 1; i < s.length(); i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			temp *= 10;
			temp += s[i] - '0';
			continue;
		}
		if (s[i] == '(')
		{
			ope.push(s[i]);
			continue;
		}
		if (judge(s[i]))
		{
			num.push(temp);
			temp = 0;
			char a;
			for (;;)
			{
				ope.get_top(a);
				if (priority(a) < priority(s[i]))
				{
					ope.push(s[i]);
					break;
				}
				else if (a == '#' && s[i] == '#')
					break;
				else
				{
					int b, c;
					num.get_top(b);
					num.pop();
					num.get_top(c);
					num.pop();
					ope.pop();
					if (a == '(')
					{
						ope.get_top(a);
						ope.pop();
						i++;
					}
					num.push(calculate(c, b, a));
					continue;
				}
			}
			continue;
		}
	}
	int result;
	num.get_top(result);
	cout << result;
	return 0;
}