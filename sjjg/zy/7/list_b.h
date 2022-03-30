#ifndef UNTITLED__LIST_H
#define UNTITLED__LIST_H

struct node
{
	int data;
	node* next, * prev;
};

class list_b
{
public:
	list_b();
	~list_b();
	bool append(int pos, int num);
	bool pop(int pos);
	node* get_loc(int pos);
	int length();
	bool get_data(int pos, int& x);
protected:
	node* head;
};

#endif //UNTITLED__LIST_H

list_b::list_b()
{
	head = new node;
	head->next = head->prev = head;
	head->data = 0;
}
int list_b::length()
{
	return head->data;
}
node* list_b::get_loc(int pos)
{
	if (pos > length() || pos <= 0)
		return nullptr;
	node* temp = head;
	for (int i = 0; i < pos; i++)
		temp = temp->next;
	return temp;
}
bool list_b::append(int pos, int num)
{
	node* p = get_loc(pos);
	if (pos == length() + 1)
		p = head;
	if (p == nullptr)
		return false;
	node* s = new node;
	s->data = num;
	s->next = p;
	s->prev = p->prev;
	p->prev->next = s;
	p->prev = s;
	head->data++;
	return true;
}
bool list_b::pop(int pos)
{
	node* s = get_loc(pos);
	if (length() == 0)
		return false;
	if (length() == 1)
		head->next = head->prev = head;
	else
	{
		s->prev->next = s->next;
		s->next->prev = s->prev;
	}
	delete s;
	head->data--;
	return true;
}
list_b::~list_b()
{
	while (length() != 0)
		pop(1);
	delete head;
}
bool list_b::get_data(int pos, int& x)
{
	node* temp = get_loc(pos);
	if (temp == nullptr)
		return false;
	x = get_loc(pos)->data;
	return true;
}
