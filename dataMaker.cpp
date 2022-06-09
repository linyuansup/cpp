#include <bits/stdc++.h>
using namespace std;
vector<int> randData(int n)
{
	unsigned seed = time(0);
	srand(seed);
	vector<int> data;
	for (int i = 0; i < n; i++)
		data.insert(data.end(), rand());
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
void writeFile(const vector<int> data, char* filePath)
{
	freopen(filePath, "w", stdout);
	for (auto pos = data.begin(); pos != data.end(); pos++)
		cout << *pos;
}
int main()
{

}