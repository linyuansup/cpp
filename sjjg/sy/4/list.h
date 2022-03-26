#ifndef UNTITLED__LIST_H
#define UNTITLED__LIST_H

struct node
{
	int data;
	node* next, * prev;
};

class list
{
public:
	list();
	~list();
	bool append(int pos, int num);
	bool pop(int pos);
	bool empty();
	node* get_loc(int pos);
	int length();
	bool get_data(int pos, int& x);
	bool reserve();
	node* get_head();
protected:
	node* head;
	static void swa(node* pos, node* temp);
};

#endif //UNTITLED__LIST_H

list::list()
{
	head = new node;
	head->next = head->prev = head;
	head->data = 0;
}
int list::length()
{
	return head->data;
}
bool list::empty()
{
	return (length() == 0);
}
node* list::get_loc(int pos)
{
	if (pos > length() || pos <= 0)
		return nullptr;
	node* temp = head;
	for (int i = 0; i < pos; i++)
		temp = temp->next;
	return temp;
}
bool list::append(int pos, int num)
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
bool list::pop(int pos)
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
list::~list()
{
	while (length() != 0)
		pop(1);
	delete head;
}
bool list::get_data(int pos, int& x)
{
	node* temp = get_loc(pos);
	if (temp == nullptr)
		return false;
	x = get_loc(pos)->data;
	return true;
}
bool list::reserve()
{
	if (empty())
		return false;
	node* pos, * temp = nullptr;
	swa(head, temp);
	for (int i = 1; i <= length(); i++)
	{
		pos = get_loc(i);
		swa(pos, temp);
	}
	return true;
}
void list::swa(node* pos, node* temp)
{
	temp = pos->next;
	pos->next = pos->prev;
	pos->prev = temp;
}
node* list::get_head()
{
	return head;
}