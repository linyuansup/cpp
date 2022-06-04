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
}
void Graph::getChoice(int num)
{
	bool temp = false;
	num--;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			if (nodeData[j][i] == 1)
			{
				temp = true;
				break;
			}
		if (temp)
		{
			choice[num].push(i);
			temp = false;
		}
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
}
void Graph::set(int num)
{
	num--;
	for (int i = 0; i < size; i++)
		if (nodeData[num][i] == 0)
			nodeData[num][i] = -2;
		else
			nodeData[num][i] = -1;
}
queue<vector<int>> Graph::TSort()
{
	queue<vector<int>> returnData;
	vector<int> thisData;
	int nowData;
	for (int i = 0; i < size; i++)
	{
		getChoice(i);
		if (!(choice[i].empty()))
		{
			nowData = choice[i].front();
			set(nowData);
			thisData.insert(thisData.end(), nowData);
			choice[i].pop();
		}
		if (i == size - 1 || choice[i].empty())
		{
			if (i == size - 1)
				returnData.push(thisData);
			i -= 2;
			reset(*thisData.end());
			thisData.erase(thisData.end());
		}
	}
	return returnData;
}

#endif //UNTITLED__GRAPH_H
