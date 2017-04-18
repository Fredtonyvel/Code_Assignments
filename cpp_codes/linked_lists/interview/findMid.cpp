#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node *next;
};

class list
{
public:
	Node *InsertEnd(Node *head, int data)
	{
		Node *tmp, *ptr = new Node();
		ptr->data = data;
		ptr->next = NULL;

		if(head == NULL)
			head = ptr;
		else
		{
			for(head = ptr; ptr->next != NULL; ptr = ptr->next);

		}
	}

private:
	Node *hp, *tp;
};

int main()
{

	return 0;

}