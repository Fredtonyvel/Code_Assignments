#include <cstdlib>
#include <iostream>

#include "list.h"

using namespace std;

list::~list()
{
	cout << "Deleting list..." << endl;
	for(listNode *tmp; !isEmpty();)
	{
		tmp = head->next;
		delete head;
		head = tmp;
	}
	cout << "Size of list = " << listSize() << endl;
}

bool list::isInList(int data)
{
	listNode *tmp = head;
	for (tmp = head; tmp != NULL && !(tmp->data == data); tmp = tmp->next);
	return true;	
}

void list::addToHead(int data)
{
	head = new listNode(data, head);
	if (tail == NULL)
		tail = head;		
}

void list::addToTail(int data)
{
	if (tail != NULL)
	{
		tail->next = new listNode(data);
		tail = tail->next;
	}
	else
		head = tail = new listNode(data);
}

void list::addToPosition(int data, int pos)
{
	if (pos == 1)
	{
		addToHead(data);
	}
	else
	{
		listNode *tmp, *ptr = new listNode(data);
		tmp = head;
		for (int i = 0; i < pos-2; i++)
		{
			tmp = tmp->next;
		}
		ptr->next = tmp->next;
		tmp->next = ptr;
	}
}

int list::deleteFromHead()
{
	int el = head->data;
	listNode *tmp = head;
	if (head == tail)
		head = tail = NULL;
	else
		head = head->next;
	delete tmp;

	return el;
}

int list::deleteFromTail()
{
	int el = tail->data;
	if (head == tail)
	{
		delete head;
		head = tail = NULL;
	}
	else
	{
		listNode *tmp;
		for (tmp = head; tmp->next != tail; tmp = tmp->next);
		delete tail;
		tail = tmp;
		tail->next = NULL;
	}
	return el;
}

int list::deleteNode(int data)
{
	if (head != NULL)
	{
		if (head == tail && data == head->data)
		{
			delete head;
			head = tail = NULL;
		}
		else if (data == head->data)
		{
			listNode *tmp = head;
			head = head->next;
			delete tmp;
		}
		else
		{
			listNode *pred, *tmp;
			for (pred = head, tmp = head->next; tmp != NULL && !(tmp->data == data); pred = pred->next, tmp = tmp->next);
			if (tmp != NULL)
			{
				pred->next = tmp->next;
				if (tmp == tail)
					tail = pred;
				delete tmp;
			}
		}
	}
	return data;
}

int list::listSize()
{
	int count = 0;
	listNode *ptr;
	for (ptr = head; ptr != NULL; ptr = ptr->next)
	{
		count++;
	}
	return count;
}

void list::printList()
{
	listNode *tmp;
	tmp = head;
	cout << "List: ";
	while(tmp != NULL)
	{
		cout << tmp->data << " -> ";
		tmp = tmp->next;
	}
	cout << "NULL" << endl;
}