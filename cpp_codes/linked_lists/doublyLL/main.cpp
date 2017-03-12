#include "doubleList.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	cout << "Doubly Linked List program\n\n";

	doubleList<int> dLL;
	dLL.addToDLLTail(10);
	dLL.addToDLLTail(20);
	dLL.addToDLLTail(30);
	dLL.addToDLLTail(40);
	dLL.addToDLLTail(50);
	dLL.printList();

	doubleList<string> dLL2;	
	dLL2.addToDLLTail("Freddy");
	dLL2.addToDLLTail("Gary");
	dLL2.addToDLLTail("John");
	dLL2.printList();

	return 0;
}