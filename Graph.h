#ifndef CODE__GRAPH_H
#define CODE__GRAPH_H
#include <vector>
#include <string>
#include <stack>

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
	void deleteChild(node* parent);
	~Graph();
public:
	Graph() = default;
	Graph(int n, string data);
};

Graph::Graph(int n, string data)
{
	nodePour.resize(n);
	auto nodePourPos = nodePour.begin();
	auto nowPos = *nodePourPos;
	for (char& stringPos : data)
	{
		if (stringPos == '.')
			nowPos = *(++nodePourPos);
		else
		{
			nowPos = new node;
			nowPos->data = stringPos - '0';
			nowPos = nowPos->next;
		}
	}
}

void Graph::deleteChild(node* parent)
{
	stack<node*> child;
	if (parent != nullptr)
	{
		child.push(parent);
		parent = parent->next;
	}
	while (!child.empty())
	{
		parent = child.top();
		delete[] parent;
		child.pop();
	}
}

Graph::~Graph()
{
	for (auto& pos : nodePour)
		deleteChild(pos);
}

#endif //CODE__GRAPH_H
