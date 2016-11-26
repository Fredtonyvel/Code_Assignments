#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node* next;
};

Node* head = NULL;

void InsertFront(int value)
{
	Node* tmp = new Node;
	tmp->data = value;
	if (head == NULL)
	{
		tmp->next = NULL;
		head = tmp;
	}
	else
	{
		tmp->next = head;
		head = tmp;
	}
}

void InsertEnd(int value)
{
	Node* tmp = new Node;
	tmp->data = value;
	tmp->next = NULL;
	if (head == NULL)
	{
		head = tmp;
	}
	else
	{
		Node* tmp2 = head;
		while(tmp2->next != NULL)
		{
			tmp2 = tmp2->next;
		}
		tmp2->next = tmp;
	}
}

void printList()
{
	Node* tmp = head;
	if (tmp == NULL)
	{
		cout << "List is empty!" << endl;
	}
	else
	{
		cout << "List: ";
		while(tmp != NULL)
		{
			cout << tmp->data << " ";
			tmp = tmp->next;
		}
		cout << endl;
	}
}

int main()
{
	printList();
	InsertEnd(15);
	InsertEnd(15);
	InsertFront(20);
	printList();

	return 0;
}