#ifndef STACK
#define STACK

class stackNode
{
public:
	int data;
	stackNode *next;

	stackNode()
	{
		next = NULL;
	}
	stackNode(int info, stackNode *ptr = NULL)
	{
		data = info;
		next = ptr;
	}
};

class stack
{
private:
	stackNode *head, *tail;

public:
	stack()
	{
		head = NULL;
		tail = NULL;
	}
	~stack();

	int isEmpty()
	{
		return head == NULL;
	}
	void push(int);
	int pop();
	int top();
	int size();
};

#endif /* STACK */