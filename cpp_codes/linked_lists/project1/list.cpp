#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <sstream>

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

//Function to insert professor into the list in alphabetical sorted order
/*
Cases handled:
 + add to list when empty
 + add to list alphabetically by last name
 + add to list alphabetically by first name only when last names are the same
*/
void list::insert(const Professor &professor)
{
	Node *curr = head; //current ptr points to the first node in the list
	Node *prev = NULL;
	Node *tmp = new Node(professor);

	if(head == NULL) //when list is empty
	{
		head = new Node(professor, head);
		if(tail == NULL)
			tail = head;
	}
	else
	{
		while(curr != NULL) //loop runs until end of list is reached
		{
			if(curr->professor.getLastName() > professor.getLastName()) //checks list if the current professor's last name > the last name of the professor being inserted
			{
				if(prev == NULL) //means that the new node has been to be inserted in the front of the list 
				{
					head = new Node(professor, head);
					curr = head;
					break; //break statements used to break out of the while loop
				}
				else if(prev != NULL && prev->professor.getLastName() < professor.getLastName()) // insert node after the current object since professor's last name is > than current professor's last name  
				{
					tmp->next = prev->next;
					prev->next = tmp;
					break;
				}
			}
			else if(curr->professor.getLastName() == professor.getLastName()) //if last name of the current professor is the same as new professor, then sort by first name
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
			else if(curr->next == NULL) //the new professor's last name is greater than the rest on the list and is inserted at the end
			{
				curr->next = tmp;
				tail = tmp;
				break;
			}
			else //point the previous node to the current node and increment current point 
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

void list::display()
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
 
void list::save()
{
	ofstream file("Database_test.csv");
	if (!file.good())
	{
		cout << "File could not be opened" << endl;
		return;
	}

	Node *ptr = head;
	file << left << "Last Name" << "," << "First Name" << "," 
		 << "Office #" << "," << "Email" << "," << "Phone #" << endl;
	while (ptr != NULL)
	{
		file << left << ptr->professor.getLastName();
		file << left << "," << ptr->professor.getFirstName();
		file << left << "," << ptr->professor.getRoomNum();
		file << left << "," << ptr->professor.getEmail();
		file << left << "," << ptr->professor.getPhone() << endl;

		ptr = ptr->next;
	}

	cout << "\nList saved to file" << endl;
	file.close();
}

void list::load()
{
	ifstream file("Database_test.csv");
	string line;

	if(!file.good())
	{
		cout << "File could not be opened" << endl;
		return;
	}

	getline(file, line); //skip first line which is the title
	//cout << "line = " << line << endl;
	
	vector<string> v_ln;
	vector<string> v_fn;
	vector<string> v_rm;
	vector<string> v_em;
	vector<string> v_ph;
	int row = 0;
	string ln, fn, rm, em, ph;

	while(getline(file,line))
	{
		stringstream text(line);

		getline(text, ln, ',');
		v_ln.push_back(ln);

		getline(text, fn, ',');
		v_fn.push_back(fn);

		getline(text, rm, ',');
		v_rm.push_back(rm);

		getline(text, em, ',');
		v_em.push_back(em);

		getline(text, ph);
		v_ph.push_back(ph);

		row++;
	}

	Professor profArray;
	cout << "\nDisplaying Professor Information" << endl;
	cout << "------------------------------" << endl;
	for(int i = 0; i < row; i++)
	{
		Professor profArray(v_fn[i], v_ln[i], v_rm[i], v_em[i], v_ph[i]);
		insert(profArray);
	}

	cout << "File loaded to screen" << endl;

	file.close();
}