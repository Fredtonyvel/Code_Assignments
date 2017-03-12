#ifndef DOUBLELIST_H
#define DOUBLELIST_H

#include <iostream>

using namespace std;

template<class T>
class DLLNode
{
public:
	DLLNode()
	{
		next = prev = 0;
	}
	DLLNode(const T& el, DLLNode *n = 0, DLLNode *p = 0)
	{
		info = el;
		next = n;
		prev = p;
	}

	T info;
	DLLNode *next, *prev;	
};

template<class T>
class doubleList
{
public:
	doubleList()
	{
		head = tail = 0;
	}
	void addToDLLTail(const T&);
	T deleteFromDLLTail();
	void printList();

protected:
	DLLNode<T> *head, *tail;
};

template<class T>
void doubleList<T>::addToDLLTail(const T& data)
{
	if (tail != 0)
	{
		tail = new DLLNode<T>(data,0,tail);
		tail->prev->next = tail;
	}
	else
		head = tail = new DLLNode<T>(data);
}

template<class T>
T doubleList<T>::deleteFromDLLTail()
{
	T data = tail->info;
	if (head == tail) //if only one node in the list
	{
		delete head;
		head = tail = 0;
	}
	else //if more that one node in the list
	{
		tail = tail->prev;
		delete tail->next;
		tail->next = 0;
	}
	return data;
}

template<class T>
void doubleList<T>::printList()
{
	DLLNode<T> *ptr = head;
	int i = 0;

	cout << "DLL: \n";
	while(ptr != NULL)
	{
		cout << i << " = " 
		     << ptr->prev << "\t" 
			 << ptr->info << "\t" 
			 << ptr->next << endl;
		ptr = ptr->next;
		i++;
	}
} 

#endif //DOUBLELIST_H