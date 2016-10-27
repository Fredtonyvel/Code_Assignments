#include <cstdlib>
#include <iostream>
#include <string>

#include "hash.h"

using namespace std;

//constructor
hash::hash()
{
	//Setting default values using linked list in an array
	for (int i = 0; i < tableSize; i++)
	{
		HashTable[i] = new item;
		HashTable[i]->name = "empty";
		HashTable[i]->drink = "empty";
		HashTable[i]->next = NULL;
	}
}

void hash::AddItem(string name, string drink)
{
	int index = Hash(name);
	
	if (HashTable[index]->name == "empty")
	{
		HashTable[index]->name = name;
		HashTable[index]->drink = drink;	
	}
	else
	{
		item* Ptr = HashTable[index];
		item* n = new item;
		n->name = name;
		n->drink = drink;
		n->next = NULL;
		while(Ptr->next != NULL)
		{
			Ptr = Ptr->next;
		}
		Ptr->next = n;
	}
}

int hash::NumberOfItemsInIndex(int index)
{
	int count = 0;

	if (HashTable[index]->name == "empty")
	{
		return count;
	}
	else
	{
		count++;
		item* Ptr = HashTable[index];
		while(Ptr->next != NULL)
		{
			count++;
			Ptr = Ptr->next;
		}
	}
	return count;
}

void hash::PrintTable()
{
	int number;

	for (int i = 0; i < tableSize; i++)
	{
		number = NumberOfItemsInIndex(i);
		cout << "----------------------\n";
		cout << "index = " << i << endl;
		cout << HashTable[i]->name << endl;
		cout << HashTable[i]->drink << endl;
		cout << "# of items = " << number << endl;
		cout << "----------------------\n\n";
	}
}

void hash::PrintItemsinIndex(int index)
{
	item* Ptr = HashTable[index];

	if (Ptr->name == "empty")
	{
		cout << "index = " << index << " is empty" << endl;
	}
	else
	{
		cout << "index " << index << " contains the following items\n";

		while(Ptr != NULL)
		{
			cout << "-----------------\n";
			cout << Ptr->name << endl;
			cout << Ptr->drink << endl;
			cout << "-----------------\n\n";
			Ptr = Ptr->next;
		}
	}
}

int hash::Hash(string key)
{
	int hash = 0;
	int index;

	//Add the value of hash to each element in the string
	for (int j = 0; j < key.length(); j++)
	{
		hash = hash + (int)key[j];
		//cout << "Hash = " << hash << endl;
	}

	/*Take the value of hash and mod it by the tableSize
	to get the hashed index*/
	index = hash % tableSize;

	return index;
}	

int main()
{
	hash obj;
	//obj.PrintTable();

	/*int num;
	string name, drink;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> name >> drink;
		obj.AddItem(name, drink);
	}*/

	obj.AddItem("Freddy Jr", "Water");
	obj.AddItem("Gary", "Water");
	obj.AddItem("Ashok", "Tea");
	obj.AddItem("Emely", "Dunkin Donuts");
	obj.AddItem("Angelica", "Starbucks");
	obj.AddItem("Danielle", "Protein Shake");
	obj.AddItem("Talhad", "Tea");
	obj.AddItem("Saad", "Orange Juice");
	obj.AddItem("Jeremy", "Soda");
	obj.AddItem("Milena", "Apple Juice");
	obj.AddItem("Jairo", "Jarritos");
	obj.AddItem("Freddy", "Orange Soda");

	//obj.PrintTable();
	//obj.PrintItemsinIndex(0);
	for (int j = 0; j < 12; j++)
	{
		obj.PrintItemsinIndex(j);
	}

	return 0;
}