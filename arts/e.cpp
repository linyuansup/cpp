#include <bits/stdc++.h>
using namespace std;
struct data
{
	string str;
	int pos{};
	// 由于排序针对于结构体进行，需要写运算符重载
	bool operator<(const data& y) const
	{
		return str < y.str;
	}
};
int main()
{
	int k, mode, m1, m2;
	string temp;
	// n其实是废的，直接假装输入了就行
	cin >> k >> temp >> k;
	data a[k + 1];
	// 第0位存储原始字符串，方便后面操作统一
	a[0].str = temp;
	a[0].pos = 0;
	for (int i = 1; i <= k; i++)
	{
		cin >> mode;
		// 第一种情况
		if (mode == 1)
		{
			cin >> m1 >> m2 >> temp;
			a[i].str = a[m1].str;
			a[i].pos = i;
			// 由于第0位的存在，需要将m2的数-1才对应string中的位置，下同
			a[i].str = a[i].str.replace(m2 - 1, 1, temp);
		}
		else
		{
			cin >> m1 >> m2;
			a[i].str = a[m1].str;
			a[i].pos = i;
			a[i].str = a[i].str.erase(m2 - 1, 1);
		}
	}
	// sort在对结构体进行时会整体移动，从而实现了位置信息的保留
	sort(a + 1, a + 1 + k);
	for (int i = 1; i <= k; i++)
		cout << a[i].pos << " ";
	return 0;
}