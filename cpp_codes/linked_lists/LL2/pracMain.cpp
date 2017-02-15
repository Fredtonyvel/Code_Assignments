#include "pracList.h"
#include <iostream>
#include <list>

using namespace std;

int main()
{
	List ll;
	ll.printList();
	
	/*ll.addToHead(3);
	ll.addToHead(2);
	ll.addToHead(1);
	ll.printList();*/
	
	/*ll.addToTail(1);
	ll.addToTail(2);
	ll.addToTail(3);
	ll.printList();*/
	
	//if (!ll.isEmpty())
	//	cout << "\nDeleted " << ll.deleteFromHead() << " from front of list\n";
	//if (!ll.isEmpty())
	//	cout << "\nDeleted " << ll.deleteFromTail() << " from end of list\n";
	//ll.printList();

	ll.addNode(15, 24);
	ll.printList();
	ll.addNode(23, 105);
	ll.printList();
	ll.addNode(4, 2);
	ll.printList();
	cout << "size = " << ll.size() << endl;
	return 0;
}