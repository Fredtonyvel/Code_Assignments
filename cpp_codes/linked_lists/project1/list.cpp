#include <string>
#include <iostream>

#include "Professor.h"
#include "list.h"

using namespace std;

//Destructor to delete each node in the list
list::~list()
{
	if (!isEmpty())
	{
		//cout << "\nDeleting list..." << endl;

		Node *ptr = head; //point ptr to head node
		for(; ptr != NULL; ) //Will loop until end of the list is reached
		{	
			head = head->next; //Increment head node to next node in the list
			delete ptr;
			ptr = head; //reset ptr to the next node that head is pointing to
		}
		delete head, ptr;
	}
}

int list::size()
{
	int count = 0;

	//loop to count each node in the list
	for (Node *ptr = head; ptr != NULL; ptr = ptr->next) 
		count++;
	return count;
}

//function to add new node to the front of the list
void list::addToHead(const Professor &professor)
{
	head = new Node(professor, head);
	if (tail == NULL)
		tail = head;
}

//function to add new node to the end of the list
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

//Function to add professor anywhere in list 
void list::insert(const Professor &professor)
{
	Node *curr = head;
	Node *prev = NULL;
	Node *tmp = new Node(professor);

	if(head == NULL)
	{
		head = new Node(professor, head);
		if(tail == NULL)
			tail = head;
	}
	else
	{
		while(curr != NULL)
		{
			if(curr->professor.getLastName() > professor.getLastName())
			{
				if(prev == NULL)
				{
					head = new Node(professor, head);
					curr = head;
					break; 
				}
				else if(prev != NULL && prev->professor.getLastName() < professor.getLastName())
				{
					tmp->next = prev->next;
					prev->next = tmp;
					break;
				}
				/*else
				{
					tmp->next = curr->next;
					curr->next = tmp;
					break;
				}*/
			}
			else if(curr->professor.getLastName() == professor.getLastName())
			{
				if(curr->professor.getFirstName() > professor.getFirstName() && prev == NULL)
				{
					head = new Node(professor, head);
					curr = head;
					break;
				}
				else if(curr->professor.getFirstName() > professor.getFirstName() && prev != NULL)
				{
					tmp->next = prev->next;
					prev->next = tmp;
					break;
				}
				else
				{
					prev = curr;
					curr = curr->next;
				}
			}
			else if(curr->next == NULL)
			{
				curr->next = tmp;
				tail = tmp;
				break;
			}
			else
			{
				prev = curr;
				curr = curr->next;
			}
		}
	}	
		
}

//Function to search through list for professor first and last name
string list::search(string findFName, string findLName)
{
	Node *ptr = head;

	cout << "\n\nSearching list..." << endl;

	//Traverse through the list
	for( ; ptr != NULL; ptr = ptr->next)
	{
		//Loop stops until we find a match
		if (ptr->professor.getFirstName() == findFName && ptr->professor.getLastName() == findLName)
		{
			return "\nFound: " + ptr->professor.getFirstName() 
			        + " " + ptr->professor.getLastName()
			        + "\nDisplaying info:" 
			        + "\n  Name: " + ptr->professor.getLastName() + ", " + ptr->professor.getFirstName() 
			        + "\n  Room #: " + ptr->professor.getRoomNum()  
		 			+ "\n  Email: " + ptr->professor.getEmail()  
		 			+ "\n  Phone #: " + ptr->professor.getPhone() + "\n";
		}
	}
	return "\nDidn't find: " + findFName + " " + findLName;
}

void list::print()
{
	Node *ptr = head;
	cout << "-----------  List  -----------" << endl;
	while (ptr != NULL)
	{
		cout << "------------------------------\n";
		//ptr->professor.printProf();
		cout << "  Name: " << ptr->professor.getLastName() << ", " 
			 << ptr->professor.getFirstName() << endl;
		cout << "  Room #: " << ptr->professor.getRoomNum() << endl;
		cout << "  Email: " << ptr->professor.getEmail() << endl;
		cout << "  Phone #: " << ptr->professor.getPhone() << endl;
		cout << "------------------------------\n";
		ptr = ptr->next;
	}
}