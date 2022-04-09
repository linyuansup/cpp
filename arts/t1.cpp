#include <bits/stdc++.h>
using namespace std;
int main()
{
	vector<int> vec; // 新建空vector
	srand(time(0)); // 随机数种子
	vec.reserve(10); // 避免循环插入时导致vector不断进行扩容造成的性能损失
	for (int i = 0; i < 10; i++)
		vec.push_back(rand()); // 插入内容
	cout << "1 round is ";
	for (auto ine = vec.begin(); ine != vec.end(); ine++)
		cout << *ine << " "; // 输出内容，C++11中类型推导使得我们可以用auto（无后续关键字）代替vector<int>::iterator
	cout << endl;
	vec.insert(vec.begin(), rand());
	cout << "2 round is ";
	for (auto ine = vec.begin(); ine != vec.end(); ine++)
		cout << *ine << " ";
	cout << endl;
	int a = rand();
	auto ite_find = find(vec.begin(), vec.end(), a);
	if (ite_find != vec.end()) // 没有找到时返回第二个参数
		cout << "find " << *ite_find;
	else
	{
		cout << "not found";
		vec.push_back(a);
	}
	cout << endl;
	sort(vec.begin(), vec.end());
	cout << "3 round is ";
	for (auto ine = vec.begin(); ine != vec.end(); ine++)
		cout << *ine << " ";
	cout << endl;
	vec.pop_back();
	cout << "4 round is ";
	for (auto ine = vec.begin(); ine != vec.end(); ine++)
		cout << *ine << " ";
	cout << endl;
	vec.clear();
	return 0;
}