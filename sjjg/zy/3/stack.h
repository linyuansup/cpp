#ifndef UNTITLED_STACK_H
#define UNTITLED_STACK_H
enum e_code
{
	overflow,
	underflow,
	success
};
const int max_len = 10;
template<class T>
class stack
{
public:
	stack();
	bool empty() const;
	bool full() const;
	e_code get_top(T& x);
	e_code push(T x);
	e_code pop();
private:
	int count;
	T data[max_len];
};
#endif

template<class T>
stack<T>::stack()
{
	count = 0;
}
template<class T>
e_code stack<T>::pop()
{
	if (empty())
		return underflow;
	count--;
	return success;
}
template<class T>
bool stack<T>::empty() const
{
	return count == 0;
}
template<class T>
bool stack<T>::full() const
{
	return count == max_len;
}
template<class T>
e_code stack<T>::get_top(T& x)
{
	if (empty())
		return overflow;
	else
	{
		x = data[count - 1];
		return success;
	}
}
template<class T>
e_code stack<T>::push(const T x)
{
	if (full())
		return overflow;
	data[count] = x;
	count++;
	return success;
}