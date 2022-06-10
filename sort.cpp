#include <bits/stdc++.h>
using namespace std;
vector<int> readFile(const char* filePath)
{
	freopen(filePath, "r", stdin);
	vector<int> data;
	for (int& pos : data)
		cin >> pos;
	return data;
}
void bubbleSort(vector<int>& data)
{
	for (int i = 0; i < data.size(); i++)
		for (int j = 0; j < data.size() - i - 1; j++)
			if (data[j] > data[j + 1])
				swap(data[j], data[j + 1]);
}
void quickSort(vector<int>& data, int left, int right)
{
	if (left >= right)
		return;
	int i = left, j = right;
	int pivot = data[(left + right) / 2];
	while (i <= j)
	{
		while (data[i] < pivot)
			i++;
		while (data[j] > pivot)
			j--;
		if (i <= j)
		{
			swap(data[i], data[j]);
			i++;
			j--;
		}
	}
	quickSort(data, left, j);
	quickSort(data, i, right);
}
void quickSort(vector<int>& data)
{
	quickSort(data, 0, (int)data.size() - 1);
}
void mergeSort(vector<int>& data, int left, int right)
{
	if (left >= right)
		return;
	int mid = (left + right) / 2;
	mergeSort(data, left, mid);
	mergeSort(data, mid + 1, right);
	vector<int> temp;
	int i = left, j = mid + 1;
	while (i <= mid && j <= right)
	{
		if (data[i] < data[j])
			temp.insert(temp.end(), data[i++]);
		else
			temp.insert(temp.end(), data[j++]);
	}
	while (i <= mid)
		temp.insert(temp.end(), data[i++]);
	while (j <= right)
		temp.insert(temp.end(), data[j++]);
	for (int i = left; i <= right; i++)
		data[i] = temp[i - left];
}
void mergeSort(vector<int>& data)
{
	mergeSort(data, 0, (int)data.size() - 1);
}
void shellSort(vector<int>& data)
{
	int gap = (int)data.size() / 2;
	while (gap > 0)
	{
		for (int i = gap; i < data.size(); i++)
		{
			int temp = data[i];
			int j = i;
			while (j >= gap && data[j - gap] > temp)
			{
				data[j] = data[j - gap];
				j -= gap;
			}
			data[j] = temp;
		}
		gap /= 2;
	}
}
void chooseSort(vector<int>& data)
{
	for (int i = 0; i < data.size(); i++)
	{
		int min = i;
		for (int j = i + 1; j < data.size(); j++)
			if (data[j] < data[min])
				min = j;
		swap(data[i], data[min]);
	}
}
void insertSort(vector<int>& data)
{
	for (int i = 1; i < data.size(); i++)
	{
		int temp = data[i];
		int j = i;
		while (j > 0 && data[j - 1] > temp)
		{
			data[j] = data[j - 1];
			j--;
		}
		data[j] = temp;
	}
}
void log(const string& message)
{
	time_t now = time(nullptr);
	cout << ctime(&now) << message << endl;
}
int main()
{
	log("Hello world");
	return 0;
}