#include <bits/stdc++.h>
using namespace std;
int main()
{
	string str1, str2;
	cin >> str1 >> str2;
	int m = (int)str1.length() + 1, n = (int)str2.length() + 1, length[m][n], data[m][n];
	//length记录最大子序列的长度，data存储每次字符串的匹配状态
	memset(data, 100, sizeof(data));
	for (int i = 0; i < m; i++)
		length[i][0] = 0; //初始化第1列
	for (int j = 0; j < n; j++)
		length[0][j] = 0; //初始化第1行
	for (int i = 1; i < m; i++)
		for (int j = 1; j < n; j++)
			if (str1[i - 1] == str2[j - 1])
			{
				length[i][j] = length[i - 1][j - 1] + 1;
				data[i][j] = 0;
			}
			else if (length[i][j - 1] >= length[i - 1][j])
			{
				length[i][j] = length[i][j - 1];
				data[i][j] = -1;  //列数减一
			}
			else
			{
				length[i][j] = length[i - 1][j];
				data[i][j] = 1;  //行数减一
			}
	//打印最长子序列
	stack<char> lcs;
	for (int i = m - 1, j = n - 1; i >= 0 && j >= 0;)
		if (data[i][j] == 0) //说明str1的第i个元素和str2的第j个元素相同
		{
			lcs.push(str1[i - 1]);
			i--;
			j--;
		}
		else if (data[i][j] == 1) //行数减一
			i--;
		else //列数减一
			j--;
	if (lcs.empty())
		cout << "No!" << endl;
	while (!lcs.empty())
	{
		cout << lcs.top();
		lcs.pop();
	}
	return 0;
}