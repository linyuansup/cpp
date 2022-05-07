#ifndef LTY__LIST_BTREE_H
#define LTY__LIST_BTREE_H
#include <bits/stdc++.h>
using namespace std;
class list_btree
{
private:
	struct node
	{
		char data;
		node* left, * right;
	};
	int i{};
	node* root{};
	void destroy(node*& pos);
	void build(node*& pos, string data);
	int height_a(node*& pos);
	int height_b(node*& pos);
public:
	~list_btree();
	list_btree();
	explicit list_btree(const string& data);
	int get_high_a();
	int get_high_b();
};
list_btree::list_btree(const string& data)
{
	i = -1;
	build(root, data);
}
list_btree::list_btree()
{
	root = new node;
	root->data = 0;
	root->left = nullptr;
	root->right = nullptr;
}
void list_btree::build(node*& pos, string data)
{
	if (data[++i] != '.')
	{
		pos = new node;
		pos->data = data[i];
		build(pos->left, data);
		build(pos->right, data);
	}
	else
		pos = nullptr;
}
void list_btree::destroy(node*& pos)
{
	if (pos)
	{
		destroy(pos->right);
		destroy(pos->left);
		delete pos;
	}
}
list_btree::~list_btree()
{
	destroy(root);
}
int list_btree::get_high_a()
{
	return height_a(root);
}
int list_btree::height_a(node*& pos)
{
	if (pos)
		return max(height_a(pos->left) + 1, height_a(pos->right) + 1);
	return 0;
}
int list_btree::height_b(node*& pos)
{
	queue<node*> que;
	int height = 0;
	que.push(root);
	while (!que.empty())
	{
		height++;
		int size = (int)que.size();
		for (int i = 0; i < size; i++)
		{
			node* front = que.front();
			que.pop();
			if (front->left)
				que.push(front->left);
			if (front->right)
				que.push(front->right);
		}
	}
	return height;
}
int list_btree::get_high_b()
{
	return height_b(root);
}
#endif //LTY__LIST_BTREE_H