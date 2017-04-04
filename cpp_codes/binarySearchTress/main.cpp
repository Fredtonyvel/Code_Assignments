#include <iostream>

using namespace std;

struct BstNode
{
	int data;
	BstNode* left;
	BstNode* right;
};

BstNode* GetNewNode(int data)
{
	BstNode* newNode = new BstNode();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

BstNode* Insert(BstNode* root, int data)
{
	if (root == NULL) 
		root = GetNewNode(data);
	else if (root->data >= data)
		root->left = Insert(root->left, data);
	else 
		root->right = Insert(root->right, data);
	return root;
}

bool Search(BstNode* root, int data)
{
	if (root == NULL) return false;
	else if (root->data == data) return true;
	else if (root->data >= data) return Search(root->left, data);
	else return Search(root->right, data);
}

int main()
{
	cout << "Binary Search Tree Implementation" << endl;

	BstNode* root = NULL;	//not root, but root pointer

	root = Insert(root, 15);
	root = Insert(root, 10);
	root = Insert(root, 20);

	int num;
	char choice, pick;

	do
	{
		cout << "Do you want to search for number in tree? (y/n): ";
		cin >> choice;
		if (choice == 'y')
		{
			cout << "Enter number to search: ";
			cin >> num;
			if (Search(root,num) == true)
				cout << "Found " << num << endl;
			else
			{
				cout << num << " not found" << endl;
				cout << "Do you want to add " << num << "? (y/n): ";
				cin >> pick;
				if (pick == 'y')
					root = Insert(root,num);
				else
					cout << num << " not added to tree" << endl;
			}
		}
		else
			cout << "Ending search program..." << endl;
		
	} while (choice == 'y' && choice != 'n');
	
	return 0;
}

/*struct BstNode
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

//function to insert node in bst
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

//function to search node in bst
bool Search(BstNode* root, int data)
{
	if (root == NULL) return false;
	else if (root->data == data) return true;
	else if (root->data >= data) return Search(root->left,data);
	else return Search(root->right,data);
}

//printing binary search tree
void print()
{
	// insert code
}*/