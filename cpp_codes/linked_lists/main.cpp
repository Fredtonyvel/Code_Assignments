#include <cstdlib>
#include <iostream>

#include "linked_list.h"

using namespace std;

int main()
{
	linked_list obj;

	/*string name;
	int data;
	for (int i = 0; i < 5; i++)
	{
		cin >> name >> data;
		obj.FrontInsert(name, data);		
	}
	for (int i = 0; i < 5; i++)
	{
		cin >> name >> data;
		obj.AddNode(name, data);		
	}*/
	/*obj.AddNode("Freddy", 30);
	obj.AddNode("Angelica", 29);
	obj.AddNode("Anthony", 15);
	obj.AddNode("Emely", 8);
	obj.AddNode("Lolita", 25);

	obj.PrintList();
	obj.Length();

	obj.DeleteNode(8);
	obj.DeleteNode(25);
	obj.FrontInsert("Yael", 55);

	obj.PrintList();
	obj.Length();*/

	obj.InsertPos(12, 1);
	obj.InsertPos(14, 2);
	obj.InsertPos(16, 3);
	obj.InsertPos(10, 1);
	obj.InsertPos(11, 2);
	obj.PrintList();
	obj.Length();	

	return 0;
}