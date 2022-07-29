#include <iostream>
#include <ctime>
using namespace std;
#include <stdlib.h>
#include <time.h>
void maopao(int* a, int num)
{
	{
		for (int i = 0; i < num - 1; i++)
		{
			for (int j = 0; j < num - i - 1; j++)
			{
				if (a[j] > a[j + 1])
				{
					int temp = a[j];
					a[j] = a[j + 1];
					a[j + 1] = temp;
				}
			}
		}
	}
}
void xuanze(int data[], int length)
{ //简单选择排序
	int i, j, index, temp;
	for (i = 0; i < length - 1; i++)
	{
		index = i;
		for (j = i + 1; j < length; j++) //在无序区获取最小的序列
			if (data[j] < data[index])
				index = j;
		if (index != i)
		{
			temp = data[i];
			data[i] = data[index];
			data[index] = temp;
		}
	}
}

void charu(int data[], int length)
{ //直接插入排序
	int i, j, temp;
	for (i = 1; i < length; i++)
	{                   //排序进行length-1次
		temp = data[i]; //获取待插元素
		for (j = i - 1; j >= 0 && temp < data[j]; j--)
		{ //寻找插入位置
			data[j + 1] = data[j];
		}
		data[j + 1] = temp;
	}
}
void shell(int data[], int length)
{ //希尔排序
	int d, i, j, temp;
	for (d = length / 2; d >= 1; d = d / 2)
	{ //获取增量d，然后再进行这届插入排序
		for (i = d; i < length; i++)
		{
			temp = data[i]; //获取待插元素
			for (j = i - d; j >= 0 && temp < data[j]; j = j - d)
				data[j + d] = data[j];
			data[j + d] = temp;
		}
	}
}
int Partition(int data[], int first, int last)
{ //快速排序1
	int i = first, j = last, temp;
	while (i < j)
	{
		while (i < j && data[i] <= data[j])
			j--;
		if (i < j)
		{
			temp = data[i];
			data[i] = data[j];
			data[j] = temp;
			i++;
		}
		while (i < j && data[i] <= data[j])
			i++;
		if (i < j)
		{
			temp = data[i];
			data[i] = data[j];
			data[j] = temp;
			j--;
		}
	}
	return i;
}
void kuaipai(int data[], int first, int last)
{ //快速排序2
	if (first < last)
	{
		int pivot = Partition(data, first, last); //一次划分
		kuaipai(data, first, pivot - 1);          //对左侧子序列进行快速排序
		kuaipai(data, pivot + 1, last);           //对右侧子序列进行快速排序
	}
}
int Findmax(int data[], int length)
{ //桶式排序1
	int i, max;
	max = data[0];
	for (i = 1; i < length; i++)
	{
		if (data[i] > max)
			max = data[i];
	}
	return max; //获取最大值来创建桶数组
}

void tongpai(int data[], int length)
{ //桶式排序2
	int i, m;
	m = Findmax(data, length);
	int* count = new int[m + 1]; //创建桶数组
	for (i = 0; i <= m; i++)     //桶数组全部数值赋予0
		count[i] = 0;
	for (i = 0; i < length; i++) //待排序列的数值对应的桶数组下标，并其数值赋予1
		count[data[i]]++;
	for (i = 0; i <= m; i++)
	{ //取出
		while (count[i] > 0)
		{
			// cout << i << " , ";
			count[i]--;
		}
	}
}

int main() //从小到大
{
	srand((unsigned)time(NULL));
	int num;
	cout << "输入要测试的数据量：" << endl;
	cin >> num;
	int* a = new int[num];
	for (int i = 0; i < num; i++)
	{
		a[i] = rand();
	}
	int b[num];
	for (int i = 0; i < num; i++)
	{
		b[i] = a[i];
	}
	int c[num];
	for (int i = 0; i < num; i++)
	{
		c[i] = a[i];
	}
	int d[num];
	for (int i = 0; i < num; i++)
	{
		d[i] = a[i];
	}
	int e[num];
	for (int i = 0; i < num; i++)
	{
		e[i] = a[i];
	}
	int f[num];
	for (int i = 0; i < num; i++)
	{
		f[i] = a[i];
	}
	clock_t startime, endtime;
	startime = clock(); //记录开始时间
	// maopao(a, num);
	endtime = clock(); //记录结束时间
	double tot_time = (double)(endtime - startime);
	cout << "冒泡排序耗时：" << tot_time / 1000 << "s" << endl; ////////////////
	clock_t startime2, endtime2;
	startime2 = clock(); //记录开始时间
	// xuanze(b, num);
	endtime2 = clock(); //记录结束时间
	double tot_time2 = (double)(endtime2 - startime2);
	cout << "选择排序耗时：" << tot_time2 / 1000 << "s" << endl; ////////////////
	clock_t startime3, endtime3;
	startime3 = clock(); //记录开始时间
	// charu(c, num);
	endtime3 = clock(); //记录结束时间
	double tot_time3 = (double)(endtime3 - startime3);
	cout << "插入排序耗时：" << tot_time3 / 1000 << "s" << endl; ////////////////
	clock_t startime4, endtime4;
	startime4 = clock(); //记录开始时间
	shell(d, num);
	endtime4 = clock(); //记录结束时间
	double tot_time4 = (double)(endtime4 - startime4);
	cout << "希尔排序耗时：" << tot_time4 / 1000 << "s" << endl; ////////////////
	clock_t startime5, endtime5;
	startime5 = clock(); //记录开始时间
	kuaipai(e, 0, num - 1);
	endtime5 = clock(); //记录结束时间
	double tot_time5 = (double)(endtime5 - startime5);
	cout << "快速排序耗时：" << tot_time5 / 1000 << "s" << endl; ////////////////
	clock_t startime6, endtime6;
	startime6 = clock(); //记录开始时间
	tongpai(f, num);
	endtime6 = clock(); //记录结束时间
	double tot_time6 = (double)(endtime6 - startime6);
	cout << "桶排序耗时：" << tot_time6 / 1000 << "s" << endl; ////////////////
	delete[] a;

	return 0;
}
