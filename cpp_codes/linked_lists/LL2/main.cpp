#include <cstdlib>
#include <iostream>

#include "list.h"

using namespace std;

int main()
{
	list obj;

	obj.addToHead(10);
	obj.addToHead(20);
	obj.addToHead(30);

	obj.addToTail(40);
	obj.addToTail(50);
	obj.addToTail(60);

	obj.addToPosition(35, 1);
	obj.addToPosition(35, 3);
	obj.addToPosition(100, 3);

	obj.printList();
	cout << "Size of list = " << obj.listSize() << endl;

	cout << "Removed " << obj.deleteNode(30) << " from the list\n";
	obj.printList();
	cout << "Size of list = " << obj.listSize() << endl;

	cout << "Removed " << obj.deleteFromHead() << " from front of the list\n";
	cout << "Removed " << obj.deleteFromHead() << " from front of the list\n";
	cout << "Removed " << obj.deleteFromHead() << " from front of the list\n";

	obj.printList();
	cout << "Size of list = " << obj.listSize() << endl;

	cout << "Removed " << obj.deleteFromTail() << " from end of the list\n";
	cout << "Removed " << obj.deleteFromTail() << " from end of the list\n";
	cout << "Removed " << obj.deleteFromTail() << " from end of the list\n";

	obj.printList();
	cout << "Size of list = " << obj.listSize() << endl;
}