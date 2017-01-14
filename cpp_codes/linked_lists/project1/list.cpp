#include <string>
#include <iostream>

#include "Professor.h"
#include "list.h"

using namespace std;

list::~list()
{
	if (!isEmpty())
	{
		cout << "Deleting list..." << endl;

		//write code to delete each node
	}
}

void list::addToHead(const Professor &professor)
{
	if (head == NULL)
	{
		head = tail = new Node(professor);
		head->next = NULL;
	}
	else if (head->next == NULL)
	{
		Node *ptr = head;
		head = new Node(professor);
		head->next = tail = ptr;
		ptr = NULL;
	}
	else
	{
		Node *ptr = head;
		head = new Node(professor);
		head->next = ptr;
		ptr = NULL;
	}
}

void list::print()
{
	Node *ptr = head;
	cout << "List:" << endl;
	while (ptr != NULL)
	{
		//ptr->professor.printProf();
		cout << "Name: " << ptr->professor.getFirstName() << " " 
			 << ptr->professor.getLastName() << endl;
		cout << "Room #: " << ptr->professor.getRoomNum() << endl;
		cout << "Email: " << ptr->professor.getEmail() << endl;
		cout << "Phone #: " << ptr->professor.getPhone() << endl;
		ptr = ptr->next;
	}
}