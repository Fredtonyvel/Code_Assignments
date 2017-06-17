#include <iostream>
#include <string>
#include <unordered_map>

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
		ptr = new Node();
		ptr->data = data;
		ptr->next = NULL;

		if(head == NULL)
			head = ptr;
		else
		{
			for(tmp = head; tmp->next != NULL; tmp = tmp->next);
			tmp->next = ptr;	
		}

		return head;
	}

	int FindMid(Node *head)
	{
		ptr = tmp = head;
		for( ; (tmp != NULL && tmp->next != NULL); tmp = tmp->next->next, ptr=ptr->next);	
		
		return ptr->data;
	}

	void Print(Node *head)
	{
		hp = head;
		cout << "List: ";
		for( ; hp != NULL; hp = hp->next)
			cout << hp->data << " ";
		cout << endl;
	}

private:
	Node *hp, *tmp, *ptr;	
};

int main()
{
	/*list ll;
	Node *head = NULL;
	head = ll.InsertEnd(head, 10);
	head = ll.InsertEnd(head, 20);
	head = ll.InsertEnd(head, 30);
	head = ll.InsertEnd(head, 40);
	head = ll.InsertEnd(head, 50);
	head = ll.InsertEnd(head, 60);
	head = ll.InsertEnd(head, 70);
	head = ll.InsertEnd(head, 80);
	head = ll.InsertEnd(head, 90);
	head = ll.InsertEnd(head, 100);

	ll.Print(head);

	cout << "Mid node = " << ll.FindMid(head) << endl;*/

	/*unordered_map<string, int> student;
	student["Freddy"] = 515;
	student["Emely"] = 608;
	student["Angelica"] = 329;

	for(auto& x : student)
		cout << "Student name: " << x.first << "\nId# = " << x.second << endl;
	*/

	string n = "Hello";
	string m = "Halo";

	int size = n.length() + m.length();
	int count = 0;

	char words[26] = {};
	for(int i = 0; i < n.length(); i++)
	{
		words[i] = n[i];
		count++;
	}

	for(int i = 0; i < m.length(); i++)
	{
		if(m[i] == n[i])
			count--;
	}
		
	for(int i = 0; i < n.length(); i++)
		cout << words[i];

	cout << "\ncount = " << count << endl;
	return 0;

}