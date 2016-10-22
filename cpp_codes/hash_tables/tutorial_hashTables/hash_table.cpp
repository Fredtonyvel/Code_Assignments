#include <cstdlib>
#include <iostream>
#include <string>

#include "hash.h"

using namespace std;

//constructor
hash::hash()
{
	tableSize = 100;
}

int hash::Hash(string key)
{
	int hash = 0;
	int index;

	//index = key.length();

	/*for (int i = 0; i < key.size(); i++)
	{
		cout << "key[" << i << "] = " << (int)key[i] << endl;
	}*/

	//Add the value of hash to each element in the string
	for (int j = 0; j < key.length(); j++)
	{
		hash = hash + (int)key[j];
		cout << "Hash = " << hash << endl;
	}

	/*Take the value of hash and mod it by the tableSize
	to get the hashed index*/
	index = hash % tableSize;

	return index;
}	

int main()
{
	int index;
	hash hashObj;

	index = hashObj.Hash("Anthony");

	cout << "Index = " << index << endl;

	return 0;
}