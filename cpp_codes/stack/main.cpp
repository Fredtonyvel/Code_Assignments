#include <iostream>

#include "stack.h"

using namespace std;

int main()
{
	stack obj;
	obj.push(10); //10
	obj.push(20); //20 10
	obj.push(30); //30 20 10

	/*cout << "Size = " << obj.size() << endl; //3
	cout << "Top = " << obj.top() << endl; //30
	cout << "Pop = " << obj.pop() << endl; //30
	cout << "Top = " << obj.top() << endl; //20
	cout << "Size = " << obj.size() << endl; //2
	*/

	for (int i = 0; i < 3; i++)
	{
		cout << obj.top() << endl;
		obj.pop();
	}

	return 0;
}