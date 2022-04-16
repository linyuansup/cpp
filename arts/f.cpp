#include <bits/stdc++.h>
using namespace std;
int main()
{
	//横轴为时间，纵轴为位置，false表示当前时间当前位置不需要工作
	bool data[10][10] = { false };
	int n, v, x, y, a, b, l, r, q; // 与题目完全对应
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> v >> x >> y;
		for (; x <= y; x++)
			// true代表当前时间当前位置需要工作，-1为了与计算机中数组从0开始对应
			data[v - 1][x - 1] = true;
	}
	cin >> q;
	bool ans[q]; // 最终结果
	for (int i = 0; i < q; i++)
		// ans所有值设为true表示第i-1个工人在上班时间均在工作
		ans[i] = true;
	for (int i = 0; i < q; i++)
	{
		cin >> l >> r >> a >> b;
		int temp = l;
		for (; a <= b; a++)
		{
			bool con = false;
			// 一个时间点扫描完了，需要把l的值重置回去
			for (l = temp; l <= r; l++)
				if (data[l - 1][a - 1])
				{
					con = true;
					break;
					// 只要当前时间里有一点是true，则当前时间的其他点不用看了，在这个时间点必然有工作
				}
			if (!con)
			{
				// 如果有一个时间段的点都是false，则其他所有点都不用看了，答案肯定是no
				ans[i] = false;
				break;
			}
		}
	}
	for (int i = 0; i < q; i++)
	{
		if (ans[i])
			cout << "Yes";
		else
			cout << "No";
		if (i != q - 1)
			// 在不是最后一行的地方输出换行
			cout << endl;
	}
	return 0;
}