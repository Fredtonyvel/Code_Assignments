#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

#ifndef HASH_H
#define HASH_H

class hash
{
private:
	static const int tableSize = 40;  //static const allows you to use it right away

	//setting up a linked list
	struct item
	{
		string name;
		string drink;
		item* next;
	};

	item* HashTable[tableSize];

public:
	hash();
	int Hash(string key);
	void AddItem(string name, string drink);
	int NumberOfItemsInIndex(int index);
	void PrintTable();
	void PrintItemsinIndex(int index);
};


#endif  /* HASH_H */