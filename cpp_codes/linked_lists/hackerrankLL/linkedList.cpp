#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node* next;
};

bool isEmpty(Node *head)
{
	return head == NULL;
}

int length(Node* head)
{
	Node *ptr = head;
	int count = 0;

	for ( ; ptr != NULL; ptr = ptr->next)
		count++;

	return count;
}

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
		for (int i = 0; i < pos; i++)
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

Node* Search(Node *head, int data)
{
	Node *ptr = head;
	
	if(head == NULL)
		return NULL;

	for( ; ptr->data != data; ptr = ptr->next)
	{
		if(ptr->next == NULL)
			return NULL;
	}

	return ptr;
}

void Print(Node* head)
{
	Node *temp = head;

	cout << "List: ";
	while(temp != NULL)
	{
		cout << temp->data << " -> ";
		temp = temp->next;
	}
	cout << "NULL" << endl;
	cout << "List size = " << length(head) << endl;
}

void Menu()
{
	cout << "Choose # from the following options:\n";
	cout << "1. Print List\n";
	cout << "2. Insert to front of the List\n";
	cout << "3. Insert to end of the List\n";
	cout << "4. Insert to a specific spot on List\n";
	cout << "5. Delete first element from List\n";
	cout << "6. Delete last element from List\n";
	cout << "7. Delete specific element from List\n";
	cout << "8. Reverse List\n";
	cout << "9. Print size of List\n";
	cout << "10. Exit\n\n";
}

int main()
{
	cout << "Linked List - function method\n\n";
	
	int select, data, position;
	Node* head = NULL;
	
	do
	{
		Menu();
		cin >> select;

		switch(select)
		{
			case 1: Print(head);
					cout << endl;
				break;
			case 2: cout << "Enter number to insert: ";
					cin >> data;
					head = InsertFront(head, data);
					cout << "Inserted " << data << " to the front of the list\n\n";
				break;
			case 3: cout << "Enter number to insert: ";
					cin >> data;
					head = InsertEnd(head, data);
					cout << "Inserted " << data << " to the end of list\n\n";
				break;
			case 4: cout << "Enter number to insert: ";
					cin >> data;
					cout << "Enter position to insert from 0 - " << length(head)+1 << " to insert to list\n";
					cin >> position;
					if(position > length(head))
						position = length(head);
					head = Insert(head, data, position);
					cout << "Inserted " << head->data << " to position(" << position << ")\n\n";
				break;
			case 5: head = DeleteFront(head);
					cout << "Deleted first element from the list\n\n";
				break;
			case 6: head = DeleteEnd(head);
					cout << "Deleted last element from the list\n\n";
				break;
			case 7: Print(head);
					cout << "Enter element you want to delete from list: ";
					cin >> data;
					head = Delete(head, data);
					cout << "Deleted " << data << " from the list\n\n";
				break;
			case 8: Reverse(head);
					cout << "List reversed" << endl;
				break;
			case 9: cout << "List size = " << length(head) << endl << endl;
				break;
			case 10: cout << "Goodbye!\n\n";
				break;
			default: cout << "Enter valid number!" << endl;
		}
	} while (select != 10 && select <= 10);

	//Node* head = NULL;
	/*Print(head);
	cout << "List size = " << length(head) << endl;
	
	head = InsertEnd(head, 40);
	head = InsertEnd(head, 50);
	head = InsertEnd(head, 60);
	Print(head);
	cout << "List size = " << length(head) << endl;

	head = InsertFront(head, 30);
	head = InsertFront(head, 20);
	head = InsertFront(head, 10);
	Print(head);
	cout << "List size = " << length(head) << endl;

	head = Reverse(head);
	Print(head);
	cout << "List size = " << length(head) << endl;

	head = Reverse(head);
	head = Insert(head,15,2);
	Print(head);
	cout << "List size = " << length(head) << endl;

	head = Reverse(head);
	Print(head);
	cout << "List size = " << length(head) << endl;

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
	
	Node *found = Search(head, 10);

	if (found != NULL)
		cout << "Found " << found->data << " in list" << endl;
	else
		cout << "Element not found on list" << endl;
	*/
	return 0;
}