#ifndef LTY__TREE_H
#define LTY__TREE_H
#include <bits/stdc++.h>
using namespace std;
class tree
{
private:
	struct node
	{
		node* next_brother, * first_son;
		char data;
	};
	node* root{};
	int i{};
	queue<node**> que;
	void build(string& s, node** pos);
	int height_a(node* pos);
	int height_b(node* pos);
	void destroy(node*& pos);
public:
	tree() = default;
	explicit tree(string s);
	~tree();
	int get_high_a();
	int get_high_b();
	void add_tree(string s);
};
void tree::destroy(node*& pos)
{
	if (pos)
	{
		destroy(pos->next_brother);
		destroy(pos->first_son);
		delete pos;
	}
}
tree::tree(string s)
{
	i = -1;
	build(s, &root);
}
void tree::build(string& s, node** pos)
{
	if (i < (int)s.length() - 1 && s[++i] != '.')
	{
		*pos = new node;
		(*pos)->next_brother = nullptr;
		(*pos)->first_son = nullptr;
		(*pos)->data = s[i];
		que.push(pos);
		while (i < (int)s.length() - 1 && s[++i] != '.')
		{
			pos = &(*pos)->next_brother;
			*pos = new node;
			(*pos)->next_brother = nullptr;
			(*pos)->first_son = nullptr;
			(*pos)->data = s[i];
			que.push(pos);
		}
	}
	while (!que.empty())
	{
		pos = que.front();
		que.pop();
		build(s, &(*pos)->first_son);
	}
}
int tree::get_high_a()
{
	return height_a(root);
}
int tree::get_high_b()
{
	return height_b(root);
}
int tree::height_a(node* pos)
{
	if (pos)
		return max(height_a(pos->first_son) + 1, height_a(pos->next_brother));
	return 0;
}
int tree::height_b(node* pos)
{
	queue<node*> data;
	int height = 0;
	data.push(root);
	while (!data.empty())
	{
		height++;
		int size = (int)data.size();
		for (int j = 0; j < size; j++)
		{
			node* front = data.front();
			data.pop();
			if (front->first_son)
				data.push(front->first_son);
		}
	}
	return height;
}
tree::~tree()
{
	destroy(root);
}
void tree::add_tree(string s)
{
	node** pos = &root;
	pos = &(*pos)->next_brother;
	while (*pos)
		pos = &(*pos)->next_brother;
	i = -1;
	build(s, pos);
}
#endif //LTY__TREE_H
