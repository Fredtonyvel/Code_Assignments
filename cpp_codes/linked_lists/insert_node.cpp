#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

struct Node
{
	int data;
	Node* next;
};

Node* Insert(Node* head, int data)
{
	Node* temp = new Node;
	if (head == NULL)
	{
		head = temp;
		return head;
	}
	else
	{
		Node* temp2 = head;
		while(temp2->next != NULL)
		{
			temp2 = temp->next;
		}
		temp2->next = temp;
		return temp2;
	}
}

int main()
{
	Node* head = new Node;
	int data;
	cin >> data;
	cout << Insert(head, data);

	return 0;
}
