#ifndef LTY__LIST_BT_TREE_H
#define LTY__LIST_BT_TREE_H
#include <bits/stdc++.h>
using namespace std;
class tree
{
private:
	struct node
	{
		char data{};
		node* left{}, * right{}, * parent{};
		bool isLChild = true, isRChild = true;
	};
	int i{};
	node* root{};
	node* prev = nullptr;
	void destroy(node*& pos);
	void build(node** pos, string data);
	void con(node*& pos);
public:
	~tree();
	tree();
	void convent();
	string output();
	explicit tree(const string& data);
};
tree::tree(const string& data)
{
	i = -1;
	prev = nullptr;
	build(&root, data);
}
tree::tree()
{
	root = new node;
	root->data = 0;
	root->left = nullptr;
	root->right = nullptr;
}
void tree::build(node** pos, string data)
{
	if (data[++i] != '.')
	{
		*pos = new node;
		(*pos)->data = data[i];
		(*pos)->parent = prev;
		prev = *pos;
		build(&(*pos)->left, data);
		prev = *pos;
		build(&(*pos)->right, data);
	}
	else
		(*pos) = nullptr;
}
void tree::destroy(node*& pos)
{
	if (pos)
	{
		if (pos->isRChild)
			destroy(pos->right);
		if (pos->isLChild)
			destroy(pos->left);
		delete pos;
	}
}
void tree::convent()
{
	prev = nullptr;
	con(root);
}
tree::~tree()
{
	destroy(root);
}
void tree::con(node*& pos)
{
	if (pos)
	{
		con(pos->left);
		con(pos->right);
		if (pos->left == nullptr)
		{
			pos->left = prev;
			pos->isLChild = false;
		}
		if (prev != nullptr && prev->right == nullptr)
		{
			prev->right = pos;
			prev->isRChild = false;
		}
		prev = pos;
	}
}
string tree::output()
{
	string result;
	if (root)
	{
		node* pCur = root;
		prev = nullptr;
		while (pCur != nullptr)
		{
			while (pCur->left != prev && pCur->isLChild)
				pCur = pCur->left;
			while (pCur && !pCur->isRChild)
			{
				result += pCur->data;
				prev = pCur;
				pCur = pCur->right;
			}
			if (pCur == root)
				return (result + pCur->data);
			while (pCur && pCur->right == prev)
			{
				result += pCur->data;
				prev = pCur;
				pCur = pCur->parent;
			}
			if (pCur && pCur->isRChild)
				pCur = pCur->right;
		}
	}
	return "0";
}
#endif //LTY__LIST_BT_TREE_H