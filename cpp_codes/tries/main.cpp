//trie tree tutorial

#include <iostream>

using namespace std;

const int alphabet_size = 26;
const int Case = 'a';

struct Node
{
	Node *parent = NULL;
	Node *children[alphabet_size] = {};
	int occurrences = 0;
};

void InsertNode(Node *trieTree, char *word)
{
	Node *curr = trieTree;

	while(*word != '\0') //not the null terminating character
	{
		if(curr->children[*word - Case] == NULL) //if the character is NULL
		{
			curr->children[*word - Case] = new Node(); //create a new Node
			curr->children[*word - Case]->parent = curr; //make it point to parent
		}

		curr = curr->children[*word - Case]; //move the curr ptr
		++word; //increment word to the next character
	}

	++curr->occurrences; //once you get to the last character, increment occurences
}

int main()
{

	return 0;
}