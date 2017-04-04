#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node* next;
};

Node* InsertFront(Node* head, int data)
{
	Node *ptr = new Node();
	ptr->data = data;
	
	if (head == NULL)
	{
		head = ptr;
		ptr->next = NULL;
	}
	else
	{
		ptr->next = head;
		head = ptr;
	}
	
	return head;
}

Node* InsertEnd(Node* head, int data)
{
	Node *ptr = new Node();
	Node *tmp;
	ptr->data = data;
	ptr->next = NULL;

	if(head == NULL) //if list is empty
		head = ptr;
	else
	{
		tmp = head;
		for( ; tmp->next != NULL; tmp = tmp->next);
		tmp->next = ptr;
	}

	return head;
}

Node* Insert(Node *head, int data, int pos)
{
	Node *ptr = new Node();
	ptr->data = data;

	if (head == NULL)
	{
		head = ptr;
		ptr->next = NULL;
	}
	else
	{
		Node *tmp = head;
		for (int i = 1; i < pos-1; i++)
		{
			tmp = tmp->next;
		}
		ptr->next = tmp->next;
		tmp->next = ptr;
	}

	return head;
}

Node* DeleteFront(Node* head)
{
	if(head == NULL)
		cout << "List is empty" << endl;
	else
	{
		Node *ptr = head;
		head = head->next;
		delete ptr;
	}

	return head;
}

Node* DeleteEnd(Node* head)
{
	Node *prev, *ptr;
	prev = head;
	ptr = head->next;

	if(head == NULL)
		cout << "List is empty" << endl;
	else if (head->next == NULL)
	{
		delete prev, ptr;
		head = NULL;
	}

	else
	{
		for( ; ptr->next != NULL; ptr = ptr->next, prev = prev->next);
		delete ptr;
		prev->next = NULL;
	}

	return head;
}

Node* Delete(Node *head, int data)
{
	Node *prev, *ptr;
	ptr = head;

	if (head == NULL)
		cout << "List is empty" << endl;
	else if (head->data == data)
	{
		head = head->next;
		delete ptr;
	}
	else
	{
		while(ptr->data != data)
		{
			prev = ptr;
			ptr = ptr->next;
		}
		prev->next = ptr->next;
		delete ptr;
	}

	return head;
}

Node* Reverse(Node* head)
{
	Node *nxt, *curr, *prev;
	curr = head;
	prev = NULL;

	while(curr != NULL)
	{
		nxt = curr->next;
		curr->next = prev;
		prev = curr;
		curr = nxt;
	}
	head = prev;

	return head;
}

void Print(Node* head)
{
	Node *temp = head;
	while(temp != NULL)
	{
		cout << temp->data << " -> ";
		temp = temp->next;
	}
	cout << "NULL" << endl;
}

int main()
{
	cout << "Reversing List - Iterative method\n\n";

	Node* head = NULL;
	head = InsertEnd(head, 40);
	head = InsertEnd(head, 50);
	head = InsertEnd(head, 60);
	Print(head);

	head = InsertFront(head, 30);
	head = InsertFront(head, 20);
	head = InsertFront(head, 10);
	Print(head);

	head = Reverse(head);
	Print(head);

	head = Reverse(head);
	head = Insert(head,15,2);
	Print(head);

	head = Reverse(head);
	Print(head);

	head = DeleteFront(head);
	Print(head);

	head = DeleteFront(head);
	Print(head);

	head = DeleteEnd(head);
	Print(head);

	head = DeleteEnd(head);
	Print(head);

	head = Delete(head, 20);
	Print(head);

	head = Delete(head, 40);
	Print(head);

	head = Delete(head, 30);
	Print(head);	

	return 0;
}