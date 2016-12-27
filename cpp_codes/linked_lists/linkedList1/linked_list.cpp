#include <cstdlib>
#include <string>
#include <iostream>

#include "linked_list.h"

using namespace std;

linked_list::linked_list()
{
	head = NULL;
	curr = NULL;
	temp = NULL;
}

void linked_list::FrontInsert(string addName,int addData)
{
	nodePtr n = new node;
	n->name = addName;
	n->data =  addData;
	n->next = NULL;
	curr = head;

	if (head == NULL)
	{
		head = n;
	}
	else
	{
		head = n;
		head->next = curr;
	}
}

void linked_list::InsertPos(int addData, int pos)
{
	nodePtr n = new node;
	n->data = addData;
	n->next = NULL;
	curr = head;

	if (pos == 1)
	{
		n->next = head;
		head = n;
	}
	else
	{
		for (int i = 0; i < pos-2; i++)
		{
			curr = curr->next;
		}
		n->next = curr->next;
		curr->next = n;
	}
}

void linked_list::BackInsert(string addName, int addData)
{
	nodePtr n = new node;
	n->name = addName;
	n->data = addData;
	n->next = NULL;

	if (head != NULL)
	{
		curr = head;
		while(curr->next != NULL)
		{
			curr = curr->next;
		}
		curr->next = n;
	}
	else
	{
		head = n;
	}
}

void linked_list::DeleteNode(int delData)
{
	nodePtr delPtr = NULL;
	temp = head;
	curr = head;

	while(curr != NULL && curr->data != delData)
	{
		temp = curr;
		curr = curr->next;
	}
	if (curr == NULL)
	{
		cout << delData << " was not in the list\n";
		delete delPtr;
	}
	else
	{
		delPtr = curr;
		curr = curr->next;
		temp->next = curr;
		if (delPtr == head)
		{
			head = head->next;
			temp = NULL;
		}
		delete delPtr;
		cout << "The value " << delData << " was deleted\n";
	}
}

void linked_list::Length()
{
	int count = 0;
	curr = head;
	while(curr != NULL)
	{
		count++;
		curr = curr->next;
	}

	cout << "Length of the list is: " << count << endl;
}

void linked_list::PrintList()
{
	curr = head;
	cout << "\nList: ";
	while(curr != NULL)
	{
		cout << "[" << curr->name << "|" << curr->data << "|+] -> ";
		curr = curr->next;
	}
	cout << "NULL" << endl << endl;
}