#ifndef UNTITLED__LIST_H
#define UNTITLED__LIST_H

class list_a
{
public:
	list_a();
	bool append(int pos, int num);
	bool pop(int pos);
	int length() const;
	bool get_data(int pos, int& x);
protected:
	int data[50] = {};
	int count;
};

#endif

list_a::list_a()
{
	count = 0;
}
int list_a::length() const
{
	return count;
}
bool list_a::get_data(int pos, int& x)
{
	if (pos < 1 || pos > count)
		return false;
	x = data[pos - 1];
	return true;
}
bool list_a::append(int pos, int num)
{
	if (count == 50 || pos < 1 || pos > length() + 1)
		return false;
	for (int j = count; j >= pos; j--)
		data[j] = data[j - 1];
	data[pos - 1] = num;
	count++;
	return true;
}
bool list_a::pop(int pos)
{
	if (length() == 0 || pos < 1 || pos > length())
		return false;
	for (int j = pos + 1; j <= length(); j++)
		data[j - 2] = data[j - 1];
	count--;
	return true;
}
