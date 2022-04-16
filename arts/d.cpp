#include <bits/stdc++.h>
using namespace std;
// 判断是否所有类型的敌人都被击杀
bool allTypeKilled(vector<bool>& typeHasKilled, int& k)
{
	for (int i = 0; i < k; i++)
		if (!typeHasKilled[i])
			return false;
	return true;
}
int main()
{
	int n, m, k, deadNum = 0;
	cin >> n >> m >> k;
	// [0]:HP [1]:ATK [2]:type
	vector<vector<int>> enemy(n, vector<int>(3));
	// 被击杀的敌人的HP
	vector<int> blood(k, 0);
	// 被击杀的类型，T为第i类型已被击杀过
	vector<bool> typeHasKilled(k, false);
	for (int i = 0; i < n; i++)
		cin >> enemy[i][0] >> enemy[i][1] >> enemy[i][2];
	while (m)
	{
		for (int i = 0; i < n; i++)
		{
			// 所有敌人HP--
			enemy[i][1]--;
			if (!enemy[i][1])
			{
				// 如果HP为0
				deadNum++;
				typeHasKilled[i] = true;
				// 取当前类型的最大HP
				blood[enemy[i][2] - 1] = max(blood[enemy[i][2] - 1], enemy[i][0]);
			}
		}
		m--;
		if (deadNum == n)
			break;
	}
	if (allTypeKilled(typeHasKilled, k))
		// 取得所有类型HP的最小值
		cout << m + *min_element(blood.begin(), blood.end());
	else
		cout << -1;
	return 0;
}