#include <iostream>

using namespace std;

struct BstNode
{
	int data;
	BstNode* left;
	BstNode* right;
};

//funtion to create new node in dynamic memory
BstNode* GetNewNode(int data)
{
	BstNode* newNode = new BstNode();
	newNode->data = data;
	newNode->left = newNode->right = NULL;

	return newNode;
}

//function to insert
BstNode* Insert(BstNode* root, int data)
{
	if (root == NULL) //empty tree
		root = GetNewNode(data);
	else if (data <= root->data)	//Insert on left side if data less that root (recursively)	
		root->left = Insert(root->left,data);
	else
		root->right = Insert(root->right,data);	//Insert right side if data greater than root (recursively)

	return root;
}

//printing binary search tree
void print()
{
	
}

int main()
{
	cout << "Binary Search Tree Implementation" << endl;

	BstNode* root = NULL;	//not root, but root pointer

	root = Insert(root, 15);
	root = Insert(root, 10);
	root = Insert(root, 20);

	return 0;
}