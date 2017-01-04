#include <iostream>

#include "stack.h"

using namespace std;

stack::~stack()
{
	cout << "Deleting stack..." << endl;
	for (stackNode *tmp; !(isEmpty());)
	{
		tmp = head->next;
		delete head;
		head = tmp;
	}
}

void stack::push(int data)
{
	head = new stackNode(data, head);
	if (tail == NULL)
		tail = head;
}

int stack::pop()
{
	int data;
	stackNode *ptr, *tmp;
	tmp = head;
	ptr = head;

	if (head != NULL)
	{
		data = tmp->data;
		ptr = ptr->next;
		head = ptr;
		delete tmp;
	}
	return data;
}

int stack::top()
{
	int data;
	stackNode *ptr = head;

	if (head != NULL)
	{
		data = ptr->data;
	}
	return data; 
}

int stack::size()
{
	int count = 0;
	stackNode *ptr = head;

	while(ptr != NULL)
	{
		count++;
		ptr = ptr->next;
	}
	return count;
}