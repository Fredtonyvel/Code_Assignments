#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

struct Node
{
	int data;
	Node* next;
};

Node* top = NULL;

void Push(int x)
{
	Node* temp = new Node;
	temp->data = x;
	temp->next = top;
	top = temp;
}

void Pop()
{
	Node* temp;
	if (top == NULL)
	{
		cout << "Stack is empty" << endl;
	}
	temp = top;
	top = top->next;
	delete temp;
}

void Print()
{
	Node* temp = top;
	cout << "Stack: ";
	while(temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

/*Node* Insert(Node* head, int data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->next = NULL;
	if (head != NULL)
	{
		temp->next = head;
	}
	head = temp;

	return head;
}*/

int main()
{
	/*Node* head = new Node;
	head = NULL;

	cout << Insert(head, 4) << endl;*/
	Push(2);
	Print();
	Push(3);
	Print();
	Push(4);
	Print();
	Push(5);
	Print();
	Pop();
	Print();
	Push(10);
	Print();
	Pop();
	Print();



	return 0;
}