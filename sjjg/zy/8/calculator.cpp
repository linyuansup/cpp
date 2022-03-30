#include <iostream>
#include <stack>
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
		else if (s[i] == '(')
			ope.push(s[i]);
		else if (judge(s[i]))
		{
			num.push(temp);
			temp = 0;
			for (;;)
			{
				char a = ope.top();
				if (priority(a) < priority(s[i]))
				{
					ope.push(s[i]);
					break;
				}
				else if (a == '#' && s[i] == '#')
					break;
				else
				{
					int b = num.top();
					num.pop();
					int c = num.top();
					num.pop();
					ope.pop();
					if (a == '(')
					{
						a = ope.top();
						ope.pop();
						i++;
					}
					num.push(calculate(c, b, a));
				}
			}
		}
	}
	cout << num.top();
	return 0;
}