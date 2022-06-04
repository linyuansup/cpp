#ifndef CODE__GRAPH_H
#define CODE__GRAPH_H
#include <vector>
#include <string>
#include <stack>
#include <commctrl.h>

using namespace std;

class Graph
{
private:
	struct node
	{
		node* next = nullptr;
		int data{};
	};
	vector<node*> nodePour;
	vector<int> parentNum;
	void deleteChild(node* parent);
	int nextNode(int nodeNum, vector<int> exception);
public:
	Graph() = default;
	Graph(int n, string data);
	vector<string> Tsort();
	~Graph();
};

Graph::Graph(int n, string data)
{
	parentNum.insert(parentNum.begin(), n, 0);
	parentNum.resize(n);
	nodePour.resize(n);
	auto nodePourPos = nodePour.begin();
	auto nowPos = *nodePourPos;
	for (char& stringPos : data)
		if (stringPos == '.')
			nowPos = *(++nodePourPos);
		else
		{
			nowPos = new node;
			nowPos->data = stringPos - '0';
			nowPos = nowPos->next;
			parentNum[stringPos - '0']++;
		}
}

void Graph::deleteChild(node* parent)
{
	stack<node*> child;
	while (parent != nullptr)
	{
		child.push(parent);
		parent = parent->next;
	}
	while (!child.empty())
	{
		parent = child.top();
		parentNum[parent->data]--;
		delete[] parent;
		child.pop();
	}
}

Graph::~Graph()
{
	for (auto& pos : nodePour)
		deleteChild(pos);
}

vector<string> Graph::Tsort()
{
	vector<string> returnData;
	vector<int> path;
	node* pos = nullptr;

	return returnData;
}

int Graph::nextNode(int nodeNum, vector<int> exception = {})
{
	for (node* pos = nodePour[nodeNum]; pos != nullptr; pos = pos->next)
		if (parentNum[pos->data] != 0)
		{
			for (int& exceptPos : exception)
				if (exceptPos == pos->data)
					continue;
			return pos->data;
		}
	return 0;
}

#endif //CODE__GRAPH_H
