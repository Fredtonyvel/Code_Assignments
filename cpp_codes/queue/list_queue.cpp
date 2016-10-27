#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

struct Node
{
	int data;
	Node* next;
};

Node* front = NULL;
Node* rear = NULL;

void Enqueue(int x)
{
	Node* temp = new Node;
	temp->data = x;
	temp->next = NULL;
	if ((front == NULL) && (rear == NULL))
	{
		front = rear = temp;
	}
	rear->next = temp;
	rear = temp;
}

void Dequeue()
{
	Node* temp = front;
	if (front == NULL)
	{
		cout << "Nothing to dequeue" << endl;
	}
	if (front == rear)
	{
		front = rear = NULL;
	}
	else
	{
		front = front->next;
	}
	delete temp;
}

void Print()
{
	Node* temp = front;
	cout << "Queue: ";
	while(temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main()
{
	Enqueue(3);
	Print();

	return 0;
}