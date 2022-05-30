#include <bits/stdc++.h>
using namespace std;
int main()
{
	string str1, str2;
	cin >> str1 >> str2;
	int next[10], i = 1, j = 0;
	next[1] = 0;
	while (i < str2.length())
		if (j == 0 || str2[i - 1] == str2[j - 1])
		{
			i++;
			j++;
			next[i] = j;
		}
		else
			j = next[j];
	i = j = 1;
	while (i <= str1.length() && j <= str2.length())
		if (j == 0 || str1[i - 1] == str2[j - 1])
		{
			i++;
			j++;
		}
		else
			j = next[j]; //两个字符不相等，j变为当前字符串的next值
	if (j > str2.length())
		cout << i - (int)str2.length(); // 输出答案
	return 0;
}