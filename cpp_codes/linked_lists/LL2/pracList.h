#ifndef PRACLIST_H
#define PRACLIST_H

#include <iostream>
#include <string>

using namespace std;

class Node
{
public:
	int data;
	Node *next;

	Node() {next = NULL;}
	Node(int info, Node *ptr = NULL)
	{
		data = info;
		next = ptr;
	}
};

class List
{
private:
	Node *head;
	Node *tail;

public:
	List() {head = tail = NULL;}
	~List();

	int isEmpty() {return head == NULL;}
	int size();

	//Insert Node member functions
	void addToHead(int);
	void addToTail(int);
	void addNode(int, int);

	//Delete Node member functions
	int deleteFromHead();
	int deleteFromTail();
	int deleteFromList(int);
	
	void printList();
};

#endif //PRACLIST_H