#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

enum e_code
{
	overflow,
	underflow,
	success
};

const int MAX_LEN = 20;

template<class T>
class queue
{
public:
	queue();
	bool empty() const;
	bool full() const;
	e_code get_front(T& x) const;
	e_code append(const T x);
	e_code serve();

private:
	int front, rear;
	T data[MAX_LEN];
};

#endif

template<class T>
queue<T>::queue()
{
	front = rear = 0;
}
template<class T>
bool queue<T>::empty() const
{
	return front == rear;
}
template<class T>
bool queue<T>::full() const
{
	return (rear + 1) % MAX_LEN == front;
}
template<class T>
e_code queue<T>::get_front(T& x) const
{
	if (empty())
		return underflow;
	x = data[(front + 1) % MAX_LEN];
	return success;
}
template<class T>
e_code queue<T>::append(const T x)
{
	if (full())
		return overflow;
	data[rear] = x;
	rear = (rear + 1) % MAX_LEN;
	return success;
}
template<class T>
e_code queue<T>::serve()
{
	if (empty())
		return underflow;
	front = (front + 1) % MAX_LEN;
	return success;
}