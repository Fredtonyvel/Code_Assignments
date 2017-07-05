//trie tree tutorial

#include <iostream>
#include <string>

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

Node* Search(Node* trieTree, char* word)
{
	while(*word != '\0')
	{
		if (trieTree->children[*word - Case] != NULL)
		{
			trieTree = trieTree->children[*word - Case];
			++word;
		}
		else
			return NULL;
	}

	/*if (trieTree->occurrences != 0)
		return trieTree;
	else
		return NULL;*/

	return (trieTree->occurrences != 0) ? trieTree : NULL;
}

void DeleteNode(Node* trieTree, char* word)
{
	Node* curr = Search(trieTree, word); //search if word exists

	if (curr != NULL)
	{
		--curr->occurrences;
		Node* parent = NULL;
		bool isLeaf = true;

		for (int i = 0; i < alphabet_size; i++)
		{
			if (curr->children[i] != NULL)
			{
				isLeaf = false;
				break;
			}
		}

		while(curr->parent != NULL && isLeaf && curr->occurrences == 0)
		{
			parent = curr->parent;
			for (int i = 0; i < alphabet_size; i++)
			{
				if (parent->children[i] == curr)
				{
					parent->children[i] = NULL;
					delete curr;
					curr = parent;
				}
				else if (parent->children[i] != NULL)
				{
					isLeaf = false;
					break;
				}
			}
		}
	}
}

int main()
{

	

	return 0;
}