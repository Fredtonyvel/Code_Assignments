#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <string>

class linked_list
{
private:
	typedef struct node
	{
		int data;
		std::string name;
		node* next;
	}* nodePtr;
	
	nodePtr head;
	nodePtr curr;
	nodePtr temp;

public:
	linked_list();
	void FrontInsert(std::string addName, int addData);
	void InsertPos(int addData, int pos);
	void BackInsert(std::string addName, int addData);
	void DeleteNode(int delData);
	void Length();
	void PrintList();

};

#endif /* LINKED_LIST_H */
