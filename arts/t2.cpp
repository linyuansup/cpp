#include <bits/stdc++.h>
using namespace std;
int main()
{
	list<int> lis; // 新建空list
	srand(time(0)); // 随机数种子
	for (int i = 0; i < 10; i++)
		lis.push_back(rand()); // 插入内容
	cout << "1 round is ";
	for (auto ine = lis.begin(); ine != lis.end(); ine++)
		cout << *ine << " "; // 输出内容，C++11中类型推导使得我们可以用auto（无后续关键字）代替list<int>::iterator
	cout << endl;
	lis.insert(lis.begin(), rand());
	cout << "2 round is ";
	for (auto ine = lis.begin(); ine != lis.end(); ine++)
		cout << *ine << " ";
	cout << endl;
	int a = rand();
	auto ite_find = find(lis.begin(), lis.end(), a);
	if (ite_find != lis.end()) // 没有找到时返回第二个参数
		cout << "find " << *ite_find;
	else
	{
		cout << "not found";
		lis.push_back(a);
	}
	cout << endl;
	lis.sort();
	cout << "3 round is ";
	for (auto ine = lis.begin(); ine != lis.end(); ine++)
		cout << *ine << " ";
	cout << endl;
	lis.pop_back();
	cout << "4 round is ";
	for (auto ine = lis.begin(); ine != lis.end(); ine++)
		cout << *ine << " ";
	cout << endl;
	lis.clear();
	return 0;
}