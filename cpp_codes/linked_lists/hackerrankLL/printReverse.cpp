#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node* next;
};

Node* InsertFront(Node* head, int data)
{
	//head = new Node{data, head};
	head = new Node();
	head->data = data;
	head->next = head;
	return head;
}

//h
//* * * *
//
Node* InsertEnd(Node* head, int data)
{
	//Node* tail;
	//if(head == NULL)

}

void print(Node *head)
{	
	Node *ptr = head;

	while(ptr != NULL)
	{
		cout << ptr->data << " ";
		ptr = ptr->next;
	}
}

void ReversePrint(Node *head)
{
    // This is a "method-only" submission. 
    // You only need to complete this method.
	if(head == NULL);
	else if(head->next == NULL)
	{
	  cout << head->data << " ";
	}
	else
	{
	  ReversePrint(head->next);
	  cout << head->data << " ";
	} 	
}

int main()
{
	Node* head = NULL;
	Node* ptr = head;
	for (int i = 0; i < 10; i++)
	{
		head = InsertFront(head,i);
	}
	
	cout << "List: ";
	print(head);
	cout << endl;

	cout << "Reversed list: ";
	ReversePrint(head);
	cout << endl;

	return 0;
}