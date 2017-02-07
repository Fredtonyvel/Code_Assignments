#include "pracList.h"


//Destructor to destroy List
List::~List()
{	
	cout << "\nDestroying list...\n";

	Node *ptr = head;	//Declaring node ptr to point to node that head is pointing to 
	while(ptr != NULL && !isEmpty())	//traversing list until end of list of isn't empty
	{
		ptr = head->next;	//ptr moving to the next element
		delete head;	//delete head and node it's pointing to
		head = ptr;	//reset head to point to node that ptr is pointing to
	}	
}

//Inserting element to front of list
void List::addToHead(int info)
{
	//creating a new node and make head point to it
	head = new Node(info, head);	//"info" will be assigned to (data) and "head" to (next) ptr
	if (tail == NULL)	//if list is empty, point tail to what head is pointing to
		tail = head;
}

//Inserting element to the back of the list
void List::addToTail(int info)
{
	//if list is empty, add node to list 
	if (isEmpty())
		head = tail = new Node(info);	//head & tail point to newly inserted node
	else
	{
		//Otherwise, insert node after the last node in list 
		tail->next = new Node(info);
		tail = tail->next;	//Make tail point to the newly inserted node
	}
}

//Inserting element at any position on the list 
void List::addNode(int, int)
{
	
}

//Removing element from front of the list
int List::deleteFromHead(int info)
{
	return ;
}

//Removing element from back of the list
int List::deleteFromTail(int info)
{
	return ;
}

//Removing element from the list
int List::deleteFromList(int, int)
{
	return ;
}

void List::printList()
{
	//Check to see if List is empty
	if (isEmpty())
		cout << "List is empty\n";

	Node *ptr = head;
	cout << "\nList: ";
	while(ptr != NULL)	//Print elements on list until you reach the end
	{
		cout << ptr->data << " +-> ";
		ptr = ptr->next;  //move ptr to the next element
	}
	cout << "NULL\n";
}