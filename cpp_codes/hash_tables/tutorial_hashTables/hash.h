#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

#ifndef HASH_H
#define HASH_H

class hash
{
private:
	int tableSize;

public:
	hash();

	int Hash(string key);
};


#endif  /* HASH_H */