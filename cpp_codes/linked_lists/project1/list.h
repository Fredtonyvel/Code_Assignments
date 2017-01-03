#ifndef LIST_H
#define LIST_H

#include "Professor.h"

class listNode
{
public:
	std::string data;
	listNode *next;

	listNode()
	{
		next = NULL;
	}
	listNode(std::string info, listNode *ptr = NULL)
	{
		data = info;
		next = ptr;
	}
};

class list
{
private:
	listNode *head;
	listNode *tail;

public:
	list()
	{
		head = NULL;
		tail = NULL;
	}

	//~list();

	Professor* prof;
	int isEmpty()
	{
		return head == NULL;
	}
	void addToHead(Professor *info);
	void addToTail();
};

#endif /* LIST_H */