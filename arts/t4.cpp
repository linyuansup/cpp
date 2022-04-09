#include <bits/stdc++.h>
using namespace std;
#define N 10 // 皇后数量
vector<int> put_pos; // 皇后的位置
vector<int> used(N, 0); // 是否可以被放置
vector<vector<int>> ans; // 二维数组记录答案
bool put_able(int& x, int y) // 判断是否可以防止，只需判断斜线
{
	for (int i = x - 1; i >= 0; i--)
		if (x - i == abs(y - put_pos[i]))
			return false;
	return true;
}
void solution(int x)
{
	if (x >= N)
	{
		ans.push_back(put_pos); // 递归求解
		return;
	}
	for (int i = 0; i < N; ++i)
	{
		if (used[i])
			continue; // 位置已使用
		if (put_able(x, i)) // 当前位置可以放置
		{
			used[i] = true;
			put_pos.push_back(i);
			solution(x + 1);
			used[i] = false; // 再次求解成功撤销
			put_pos.pop_back();
		}
	}
}
int main()
{
	solution(0);
	for (auto& an : ans)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
				if (j != an[i])
					cout << ".";
				else
					cout << "#";
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}