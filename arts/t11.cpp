#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	int d[a][b];
	for (int i = 0; i < a; i++)
		for (int j = 0; j < b; j++)
			cin >> d[i][j];
	int sum = -999, tmp, c[b]; // sum设为-999方便后面的第一次循环直接进入
	for (int i = 0; i < a; i++)
	{
		memset(c, 0, sizeof(c));
		for (int j = i; j < a; j++) // 转化为一维求解
		{
			tmp = 0;
			for (int k = 0; k < b; k++)
			{
				c[k] += d[j][k];
				if (tmp >= 0)
					tmp += c[k];
				else
					tmp = c[k];
				if (sum < tmp)
					sum = tmp;
			}
		}
	}
	cout << sum;
}