#include "Graph.h"
#include <bits/stdc++.h>
using namespace std;
int main()
{
	Graph g;
	g.setSize(4);
	g.link(1,2);
	g.link(1,3);
	g.link(2,4);
	g.link(3,4);
	queue<vector<int>> data = g.TSort();
	return 0;
}