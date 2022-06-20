#include <bits/stdc++.h>
using namespace std;
vector<int> randData(int n)
{
	default_random_engine e;
	uniform_int_distribution<int> u(0, 2147483647);
	vector<int> data;
	for (int i = 0; i < n; i++)
		data.insert(data.end(), u(e));
	return data;
}
vector<int> sortData(int n)
{
	vector<int> data;
	for (int i = 0; i < n; i++)
		data.insert(data.end(), i);
	return data;
}
vector<int> reverseData(int n)
{
	vector<int> data;
	for (int i = n - 1; i >= 0; i--)
		data.insert(data.end(), i);
	return data;
}
void writeFile(const vector<int>& data, const char* filePath)
{
	freopen(filePath, "w", stdout);
	for (int pos : data)
		cout << pos << " ";
}
int main()
{
	for (int n = 100; n <= 1000000; n *= 10)
	{
		for (int i = 0; i < 3; i++)
		{
			vector<int> data = randData(n);
			writeFile(data, ("rand_" + to_string(n) + "_" + to_string(i) + ".txt").c_str());
		}
		vector<int> data = sortData(n);
		writeFile(data, ("sort_" + to_string(n) + ".txt").c_str());
		data = reverseData(n);
		writeFile(data, ("reverse_" + to_string(n) + ".txt").c_str());
	}
}