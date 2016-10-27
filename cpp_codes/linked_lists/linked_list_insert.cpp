//Inserting nodes at the beginning of the list

#include <iostream>

using namespace std;

struct node
{
	int data;
	node* next;
};

void Insert(node* &head, int x)
{
	node* temp = new node;
	temp->data = x;
	temp->next = NULL;
	if (head != NULL)
	{
		temp->next = head;
	}
	head = temp;
}

//Not working properly
void Insert_at_end(node* &head, int x)
{
	node* temp = new node;
	temp->data = x;
	temp->next = NULL;
	if (head != NULL)
	{
		temp->next = head->next;
	}
	temp = head;
}

void Print(node* head)
{
	cout << "List is: ";
	while(head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

int main()
{
	node* head = NULL;

	cout << "Enter amount of numbers:\n";
	int n,x;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cout << "Enter a number: ";
		cin >> x;
		//Insert(head, x);
		Insert_at_end(head,x);
	}
	Print(head);
}