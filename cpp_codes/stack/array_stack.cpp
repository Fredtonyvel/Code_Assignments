#include <iostream>
#include <cstdio>
#include <cstdlib>
#define MAX_SIZE 101

using namespace std;

int A[MAX_SIZE];
int top = -1;

void Push(int x)
{
	if (top == MAX_SIZE - 1)
	{
		cout << "Error: stack overflow\n";
	}
	A[++top] = x;
}

void Pop()
{
	if (top == -1)
	{
		cout << "Error: no element in stack\n";
	}
	top--;
}

void Print()
{
	cout << "Stack: ";
	for (int i = 0; i <= top; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
}

int main()
{
	Push(2);
	Print();
	Push(6);
	Print();
	Push(9);
	Print();
	Pop();
	Print();
	Pop();
	Print();


	return 0;
}