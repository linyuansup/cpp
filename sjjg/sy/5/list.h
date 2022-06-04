#ifndef UNTITLED_SJJG_LIST_H
#define UNTITLED_SJJG_LIST_H

struct node
{
	int data;
	node* next;
};

class list
{
public:
	list();
	int length() const;
	int getnumber(int pos);
	bool insert(int i, int x);
	bool deletenumber(int i);
private:
	node* head;
};

list::list()
{
	head = new node;
	head->next = nullptr;
	head->data = 0;
}
int list::length() const
{
	return head->data;
}
int list::getnumber(const int pos)
{
	node* p = head->next;
	int j = 1;
	while (j != pos && p != nullptr)
	{
		p = p->next;
		j++;
	}
	if (p == nullptr)
		return false;
	return p->data;
}
bool list::insert(const int i, const int x)
{
	node* p = head;
	int j = 0;
	while (j != i - 1 && p != nullptr)
	{
		p = p->next;
		j++;
	}
	if (p == nullptr)
		return false;
	node* s = new node;
	s->data = x;
	s->next = p->next;
	p->next = s;
	head->data++;
	return true;
}
bool list::deletenumber(const int i)
{
	node* p = head;
	int j = 0;
	while (j != i - 1 && p != nullptr)
	{
		p = p->next;
		j++;
	}
	if (p == nullptr || p->next == nullptr)
		return false;
	node* u = p->next;
	p->next = u->next;
	delete u;
	head->data--;
	return true;
}

#endif //UNTITLED_SJJG_LIST_H
