#include <bits/stdc++.h>
using namespace std;
struct Wall
{
	float x, up, down; //墙壁 x：横坐标 down：下端的纵坐标 up：上端的总坐标
};
Wall make(float x, float down, float up) // 狗奥墙壁
{
	Wall w{};
	w.x = x;
	w.up = up;
	w.down = down;
	return w;
}
struct point // 点的结构体
{
	float x, y;
} pt[200];
point point(float x, float y) // 构造点
{
	struct point a{};
	a.x = x;
	a.y = y;
	return a;
}
Wall wall[200][10];
int n, pn;
float mp[200][200];
float Link(int u, int v) //判断是否可连边
{
	if (pt[u].x == pt[v].x)
		return abs(pt[u].y - pt[v].y);
	for (int i = 1; i <= n; ++i)
	{
		float X = wall[i][1].x, Y;
		if (X <= pt[u].x || X >= pt[v].x)
			continue;
		Y = ((X - pt[u].x) * pt[v].y - (X - pt[v].x) * pt[u].y) / (pt[v].x - pt[u].x);
		for (int w = 1; w <= 3; ++w)
			if (Y >= wall[i][w].down && Y <= wall[i][w].up)
				return 0;
	}
	float delta_x = pt[v].x - pt[u].x, delta_y = pt[u].y - pt[v].y;
	return sqrt(delta_x * delta_x + delta_y * delta_y);
}
int main()
{
	float x, a1, a2, b1, b2;
	cin >> n;
	pt[++pn] = point(0, 5); //起点
	for (int i = 1; i <= n; ++i)
	{
		cin >> x >> a1 >> b1 >> a2 >> b2;
		wall[i][1] = make(x, 0, a1);
		pt[++pn] = point(x, a1);
		wall[i][2] = make(x, b1, a2);
		pt[++pn] = point(x, b1);
		pt[++pn] = point(x, a2);
		wall[i][3] = make(x, b2, 10);
		pt[++pn] = point(x, b2);
	} // 构造点和边
	pt[++pn] = point(10, 5);//终点
	for (int i = 1; i <= pn; ++i)
		for (int j = i + 1; j <= pn; ++j)
			mp[i][j] = mp[j][i] = Link(i, j);
	for (int k = 1; k <= pn; ++k)
		for (int i = 1; i <= pn; ++i)
			for (int j = 1; j <= pn; ++j)
				if (i != k && j != k && i != j)
					if (mp[i][k] != 0 && mp[k][j] != 0)
						if (mp[i][j] == 0)
							mp[i][j] = mp[i][k] + mp[k][j];
						else
							mp[i][j] = min(mp[i][j], mp[i][k] + mp[k][j]); // 循环查找最优解
	printf("%.2f\n", mp[1][pn]); // 格式化输出
	return 0;
}