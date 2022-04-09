#include<bits/stdc++.h>
using namespace std;
typedef struct point
{
	double x;
	double y;
} point;
point a[2000];
int n;
int ID;
bool lineCrossing(point A, point B, point C, point D) // 线相交
{
	double fC = (C.y - A.y) * (A.x - B.x) - (C.x - A.x) * (A.y - B.y);
	double fD = (D.y - A.y) * (A.x - B.x) - (D.x - A.x) * (A.y - B.y);
	return fC * fD <= 0;
}
double calculate(point a, point b) // 处理面积
{
	return (a.x + b.x) * (b.y - a.y) / 2;
}
void solve()
{
	cout << "Figure " << ID << ": ";
	for (int i = 1; i <= n; i++)
		cin >> a[i].x >> a[i].y;
	if (n <= 2) // 两个点比不可能
	{
		cout << "Impossible" << endl;
		return;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			if (i == j || i % n + 1 == j || i == j % n + 1 || i % n + 1 == j % n + 1) continue;
			if (lineCrossing(a[i], a[i % n + 1], a[j], a[j % n + 1])
				&& lineCrossing(a[j], a[j % n + 1], a[i], a[i % n + 1]))
			{
				cout << "Impossible" << endl; // 相交的情况
				return;
			}
		}
	double ans = 0;
	for (int i = 1; i <= n; i++)
		ans += calculate(a[i], a[i % n + 1]);
	printf("%.2f\n", abs(ans)); // 格式化输出
}
int main()
{
	while (cin >> n, n)
	{
		ID++;
		solve();
	}
	return 0;
}