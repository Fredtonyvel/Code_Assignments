#ifndef LIST_H
#define LIST_H

#include "Professor.h"
#include <string>

class Node
{
public:
	Professor professor;
	Node *next;
	
	Node()
	{
		next = NULL;
	}
	Node(const Professor &obj, Node *ptr = NULL)
	{
		professor = obj;
		next = ptr;
	}

};

class list
{
private:
	Node *head;
	Node *tail;

public:
	list()
	{
		head = tail = NULL;
	}

	~list();

	int isEmpty()
	{
		return head == NULL;
	}
	int size();
	void addToHead(const Professor &professor);
	void addToTail(const Professor &professor);
	void insert(const Professor &professor);
	string search(string, string);
	void display();
	void save();
	void load();
};

#endif /* LIST_H */