#include <iostream>

using namespace std;

struct node
{
	int data;
	node* link;
};

int main()
{
	node* A;
	A = NULL;

	node* temp = new node();
	temp->data = 2;
	temp->link = NULL;
	A = temp;

	//creates a new node
	temp->data = 4;
	temp->link = NULL;

	//traverse node
	node* temp1 = A;
	while(temp1->link != NULL)
	{
		temp1 = temp1->link;
	}

	temp1->link = temp;

	cout << temp->data << endl;
	cout << temp1->data << endl;

	return 0;
}