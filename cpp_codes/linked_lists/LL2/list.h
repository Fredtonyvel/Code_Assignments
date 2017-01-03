#ifndef LIST_H
#define LIST_H

class listNode
{
public:
	int data;
	listNode *next;

	listNode()	//default constructor setting next pointer to NULL
	{
		next = NULL;
	}

	listNode(int info, listNode *ptr = NULL)	//constructing a node
	{
		data = info;
		next = ptr;
	}
};

class list
{
private:
	listNode *head, *tail;	//head and tail node pointers

public:
	list()	//constructor
	{
		head = tail = NULL;
	}
	~list(); //destructor

	int isEmpty()
	{
		return head == NULL;
	}
	bool isInList(int);
	void addToHead(int);
	void addToTail(int);
	void addToPosition(int, int);
	int deleteFromHead();
	int deleteFromTail();
	int deleteNode(int);
	int listSize();
	void printList();
};

#endif /* LIST_H */