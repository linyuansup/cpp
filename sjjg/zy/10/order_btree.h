#ifndef LTY__ORDER_BTREE_H
#define LTY__ORDER_BTREE_H
#include <bits/stdc++.h>
using namespace std;
class order_btree
{
private:
	vector<int> position;
	vector<char> data;
	int i{};
	void build(string s, int pos);
public:
	order_btree() = default;
	explicit order_btree(string s);
	int get_high();
};
order_btree::order_btree(string s)
{
	i = -1;
	build(move(s), 1);
}
int order_btree::get_high() // 直接获取最大标记值即可
{
	return (int)(log(*max_element(position.begin(), position.end())) / log(2)) + 1;
}
void order_btree::build(string s, int pos)
{
	if (s[++i] != '.')
	{
		data.push_back(s[i]);
		position.push_back(pos);
		build(s, pos * 2);
		build(s, pos * 2 + 1);
	}
}
#endif //LTY__ORDER_BTREE_H