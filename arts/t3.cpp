#include <bits/stdc++.h>
using namespace std;
int main()
{
	vector<int> vec;
	int x;
	vec.reserve(10); // 避免循环插入时导致vector不断进行扩容造成的性能损失
	for (int i = 0; i < 10; i++)
	{
		cin >> x;
		vec.push_back(x);
	}
	sort(vec.begin(), vec.end());
	for (int& ite : vec) // 简化写法
		cout << ite << " ";
	cout << endl;
	sort(vec.rbegin(), vec.rend()); // 使用rbegin和rend做到倒顺
	for (int& ite : vec)
		cout << ite << " ";
	cin >> x;
	auto ite_find = find(vec.begin(), vec.end(), x);
	if (ite_find != vec.end()) // 没有找到时返回第二个参数
		cout << "find " << *ite_find;
	else
		cout << "not found";
	cout << endl;
	x = *max_element(vec.begin(), vec.end());
	cout << x << endl;
	x = *min_element(vec.begin(), vec.end());
	cout << x << endl;
	return 0;
}