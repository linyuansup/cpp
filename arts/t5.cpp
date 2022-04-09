#include <bits/stdc++.h>
using namespace std;
int num = 0; //统计走的数目
int cheese[8][8] = { 0 }; //初始化棋盘
void dfs(int x, int y)
{
	if (num == 64) // 如果遍历完则退出
		return;
	if (cheese[x][y] != 0 || (x < 0 || x > 7 || y < 0 || y > 7)) // 出界
		return;
	else  // 未出界
	{
		num++;
		cheese[x][y] = num; // 标记
		dfs(x + 2, y + 1); // 遍历
		dfs(x - 2, y - 1);
		dfs(x + 2, y - 1);
		dfs(x - 2, y + 1);
		dfs(x - 1, y - 2);
		dfs(x + 1, y - 2);
		dfs(x + 1, y + 2);
		dfs(x - 1, y + 2);
		return;
	}
}
int main()
{
	int x, y;
	cin >> x >> y;
	dfs(x - 1, y - 1);
	for (auto& i : cheese)  //输出打印测试
	{
		for (int j : i)
			cout << setw(2) << j << "  ";
		cout << endl;
	}
	return 0;
}