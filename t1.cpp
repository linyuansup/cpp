#include "stack.h"
#include <iostream>
#include <string>
using namespace std;
inline int level(const char a)
{
    switch (a)
    {
    case '#':
        return 0;
    case ')':
        return 1;
    case '+':
    case '-':
        return 2;
    case '*':
    case '/':
        return 3;
    case '(':
        return 4;
    }
    return -1;
}
inline int calculate(int a, int b, char ope)
{
    switch (ope)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a * b;
    }
    return -1;
}
int main()
{
    Stack<int> num;
    Stack<char> ope;
    string a;
    int temp = 0;
    e_code ec;
    cin >> a;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] >= '0' && a[i] <= '9')
        {
            temp *= 10;
            temp += a[i] - '0';
        }
        else
        {
            if (temp != 0)
            {
                ec = num.push(temp);
                temp = 0;
            }
            char x;
            ec = ope.get_top(x);
            if (level(a[i]) > level(x))
                ec = ope.push(a[i]);
            else
            {
                int a, b;
                a = num.pop();
                b = num.pop();
                ec = num.push(calculate(a, b, x));
                ec = ope.pop();
            }
        }
    }
    cout << calculate(num.pop(), num.pop(), ope.pop()) << endl;
    return 0;
}