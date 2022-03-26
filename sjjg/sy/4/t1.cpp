#include <iostream>
#include "list.h"
using namespace std;
inline void show(list& li)
{
	cout << li.get_head() << endl;
	for (int i = 1; i <= 10; i++)
	{
		int x;
		li.get_data(i, x);
		cout << li.get_loc(i) << " " << x << endl;
	}
}
int main()
{
	list li;
	for (int i = 1; i <= 10; i++)
		li.append(i, i);
	show(li);
	li.reserve();
	show(li);
	return 0;
}