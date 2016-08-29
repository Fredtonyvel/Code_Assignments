#include <iostream>
#include <cstring> //to include strcpy
#include <vector>
#include <algorithm>
#include <functional> //greater<T>

using namespace std;

template<class T>
void printVector(const char *s, const vector<T>& v)
{
	cout << s << " = (";
	if (v.size() == 0)
	{
		cout << ")\n";
		return;
	}
	typename vector<T>::const_iterator i = v.begin();
	for ( ; i != v.end()-1; i++)
		cout << *i << ' ';
	cout << *i << ")\n";
}

bool f1(int n)
{
	return n < 4;
}

int main() 
{
	int a[] = {1, 2, 3, 4, 5};
	vector<int> v1;	//v1 is empty, size = 0, capacity = 0
	printVector("v1", v1);	//output: v1 = ()

	for (int j = 1; j <= 5; j++)
	{
		v1.push_back(j);  //pushes 1-5 to the end of the vector
	}
	printVector("v1", v1); //output: v1 = (1 2 3 4 5)
}