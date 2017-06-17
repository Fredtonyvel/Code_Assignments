#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node *Insert(Node *head, int data)
{
    Node *ptr = head, *tmp = new Node();
    tmp->data = data;
    tmp->next = NULL;

    if (head == NULL)
    {
        head = tmp;
    }
    else
    {
        for (; ptr->next != NULL; ptr = ptr->next);
        ptr->next = tmp;
    }
    tmp->next = head;   
    return head; 
}

bool has_cycle(Node* head) 
{
    // Complete this function
    // Do not write the main method
    Node *slow = head, *fast = head;
    
    while (fast != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        
        if(slow == fast)
        {
            return true;
            break;
        }
    }
    
    return false;   
}

void Print(Node *head)
{
    Node *ptr = head;

    cout << "List = ";
    while(ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

int main()
{
    Node *head = NULL;

    head = Insert(head, 10);
    head = Insert(head, 20);
    head = Insert(head, 30);

    //Print(head);

    if (has_cycle(head) == true)
        cout << "List has cycle\n";
    else
        cout << "List doesn't have cycle\n";

    return 0;
}