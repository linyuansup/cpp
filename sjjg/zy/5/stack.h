#ifndef UNTITLED_STACK_H
#define UNTITLED_STACK_H
enum e_code
{
	overflow,
	underflow,
	success
};
template<typename T>
struct node
{
	T data;
	node* next;
};
template<class T>
class stack
{
public:
	stack();
	~stack();
	bool empty() const;
	e_code get_top(T& x);
	e_code push(T x);
	e_code pop();
private:
	node<T>* top;
};
#endif

template<class T>
stack<T>::stack()
{
	top = NULL;
}
template<class T>
e_code stack<T>::pop()
{
	if (empty())
		return underflow;
	node<T>* u = top;
	top = top->next;
	delete u;
	return success;
}
template<class T>
bool stack<T>::empty() const
{
	return top == NULL;
}
template<class T>
e_code stack<T>::get_top(T& x)
{
	if (empty())
		return overflow;
	x = top->data;
	return success;
}
template<class T>
e_code stack<T>::push(const T x)
{
	node<T>* s = new node<T>;
	s->data = x;
	s->next = top;
	top = s;
	return success;
}
template<class T>
stack<T>::~stack()
{
	while (!empty())
		pop();
}
