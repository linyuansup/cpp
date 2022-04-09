#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, i = 0, j = 1, move = 0;
	cin >> n;
	int data[n];
	for (i = 0; i < n; i++)
		cin >> data[i];
	i = 0;
	while (j != n + 1)
		if (data[i] == data[j])
			j++;
		else
		{
			data[i + 1] = data[j];
			move++;
			i++;
			j++;
		}
	if (!move)
		move--;
	for (j = 0; j < i; j++)
		cout << data[j] << " ";
	cout << endl << move;
	return 0;
}