#ifndef UNTITLED__GRAPH_H
#define UNTITLED__GRAPH_H
#include <vector>
#include <string>
#include <queue>
using namespace std;

class Graph
{
public:
	void setSize(int n);
	void link(int start, int end);
	queue<vector<int>> TSort();
private:
	vector<vector<int>> nodeData;
	vector<queue<int>> choice;
	void getChoice(int num);
	void set(int num);
	void reset(int num);
	int size;
	vector<bool> used;
};
void Graph::link(int start, int end)
{
	nodeData[start - 1][end - 1] = 1;
}
void Graph::setSize(int n)
{
	nodeData.resize(n);
	for (int i = 0; i < n; i++)
		nodeData[i].resize(n);
	choice.resize(n);
	size = n;
	used.resize(n);
	fill(used.begin(), used.end(), false);
}
void Graph::getChoice(int num)
{
	int i, j;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
			if (nodeData[j][i] == 1)
				break;
		if (j == size && !used[i])
			choice[num].push(i);
	}
}
void Graph::reset(int num)
{
	num--;
	for (int i = 0; i < size; i++)
		if (nodeData[num][i] == -2)
			nodeData[num][i] = 0;
		else
			nodeData[num][i] = 1;
	used[num] = false;
}
void Graph::set(int num)
{
	for (int i = 0; i < size; i++)
		if (nodeData[num][i] == 0)
			nodeData[num][i] = -2;
		else
			nodeData[num][i] = -1;
	used[num] = true;
}
queue<vector<int>> Graph::TSort()
{
	queue<vector<int>> returnData;
	vector<int> thisData;
	int nowData;
	bool needGetChoice = true;
	for (int i = 0; i <= size; i++)
	{
		if (needGetChoice)
			getChoice(i);
		else
			needGetChoice = true;
		if (thisData.empty() && choice[0].empty())
			break;
		if (i == size || choice[i].empty())
		{
			if (i == size)
				returnData.push(thisData);
			i -= 2;
			reset(thisData.back());
			thisData.pop_back();
			needGetChoice = false;
		}
		else
		{
			nowData = choice[i].front();
			set(nowData);
			thisData.insert(thisData.end(), nowData + 1);
			choice[i].pop();
		}
	}
	return returnData;
}

#endif //UNTITLED__GRAPH_H
