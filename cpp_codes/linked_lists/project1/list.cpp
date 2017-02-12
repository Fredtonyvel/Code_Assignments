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

int list::size()
{
	int count = 0;
	for (Node *ptr = head; ptr != NULL; ptr = ptr->next)
		count++;
	return count;
}

void list::addToHead(const Professor &professor)
{
	head = new Node(professor, head);
	if (tail == NULL)
		tail = head;
}

void list::addToTail(const Professor &professor)
{	
	if (isEmpty())
		head = tail = new Node(professor);
	else
	{
		tail->next = new Node(professor);
		tail = tail->next;
	}
}

//Fix bug issue with addNode()  
//Segmentation fault when list is empty and pos > 1
void list::addNode(const Professor &professor, int pos)
{
	if (size() < pos)
	{	
		cout << "Not enough positions on the list\n";
		cout << "List size = " << size() << endl;
		cout << "Inserting node at index " << size() << "\n\n";
		addNode(professor, size());
	}
	else if (pos == 0)
		head = new Node(professor, head);
	else
	{
		Node *ptr, *tmp, *curr = new Node(professor);
		tmp = head;
		for (int i = 0; i < pos; i++)
		{
			ptr = tmp;
			tmp = tmp->next;
		}
		ptr->next = curr;
		curr->next = tmp;
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