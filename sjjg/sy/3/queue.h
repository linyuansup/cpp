#include <cstring>
#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

template<typename T>
struct node
{
	T data;
	node* next;
};

enum e_code
{
	underflow,
	success
};

template<class T>
class queue
{
public:
	queue();
	~queue();
	bool empty() const;
	e_code get_front(T& x) const;
	e_code append(T x);
	e_code serve();

private:
	node<T>* front;
	node<T>* rear;
};

#endif

template<class T>
queue<T>::queue()
{
	front = new node<T>;
	front->next = NULL;
	rear = front;
}
template<class T>
bool queue<T>::empty() const
{
	return front == rear;
}
template<class T>
e_code queue<T>::get_front(T& x) const
{
	if (empty())
		return underflow;
	x = front->next->data;
	return success;
}
template<class T>
e_code queue<T>::append(const T x)
{
	node<T>* s = new node<T>;
	s->next = NULL;
	s->data = x;
	rear->next = s;
	rear = s;
	return success;
}
template<class T>
e_code queue<T>::serve()
{
	if (empty())
		return underflow;
	node<T>* u = front->next;
	front->next = u->next;
	delete u;
	if (front->next == NULL)
		rear = front;
	return success;
}
template<class T>
queue<T>::~queue()
{
	while (!empty())
		serve();
	delete front;
}
