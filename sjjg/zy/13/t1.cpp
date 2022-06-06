#include "Graph.h"
#include <bits/stdc++.h>
using namespace std;
int main()
{
	Graph g;
	g.setSize(10);
	g.link(1, 3);
	g.link(1, 4);
	g.link(2, 4);
	g.link(2, 5);
	g.link(3, 6);
	g.link(4, 6);
	g.link(4, 7);
	g.link(5, 7);
	g.link(6, 8);
	g.link(6, 9);
	g.link(7, 9);
	g.link(7, 10);
	g.link(8, 9);
	g.link(9, 10);
	queue<vector<int>> data = g.TSort();
	cout << "Total:" << data.size() << endl;
	while (!data.empty())
	{
		for (int& pos : data.front())
			cout << pos << " ";
		data.pop();
		cout << endl;
	}
	return 0;
}