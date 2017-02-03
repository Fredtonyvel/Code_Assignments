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
	head = new Node(professor, head);
	if (tail == NULL)
		tail = head;
}

void list::addToTail(const Professor &professor)
{
	Node *ptr = new Node(professor);
	
	if (head == NULL)
		head = tail = ptr;
	else if (tail != NULL)
	{
		tail->next = ptr;
		tail = tail->next;
	}
}

//Fix bug issue with addNode()  
//Segmentation fault when list is empty and pos > 1
void list::addNode(const Professor &professor, int pos)
{
	Node *ptr, *tmp;
	tmp = head;

	if (pos == 1)
		head = new Node(professor, head);
	else
	{
		for (int i = 0; i < pos-2; i++)
		{
			tmp = tmp->next;
		}
		ptr = new Node(professor);
		ptr->next = tmp->next;
		tmp->next = ptr;
	}
}

void list::print()
{
	Node *ptr = head;
	cout << "----------  List  ----------" << endl;
	while (ptr != NULL)
	{
		cout << "----------------------------\n";
		//ptr->professor.printProf();
		cout << "Name: " << ptr->professor.getFirstName() << " " 
			 << ptr->professor.getLastName() << endl;
		cout << "Room #: " << ptr->professor.getRoomNum() << endl;
		cout << "Email: " << ptr->professor.getEmail() << endl;
		cout << "Phone #: " << ptr->professor.getPhone() << endl;
		cout << "----------------------------\n";
		ptr = ptr->next;
	}
}






/*if (head == NULL)
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
	}*/