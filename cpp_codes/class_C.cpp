/*Sample code from Data Structures and Algorithms in C++,
Adam Drozdek textbook*/

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

	vector<int> v2(3, 7);
	printVector("v2", v2);	//output: v2 = (7 7 7)

	vector<int> ::iterator i1 = v1.begin()+1;
	vector<int> v3(i1, i1+2);
	printVector("v3", v3);	//output: v3 = (2, 3) -- size=2 capacity=2
	
	vector<int> v4(v1);	//output: v4 = (1 2 3 4 5) -- size=5 capacity=5
	printVector("v4", v4);

	vector<int> v5(5);
	printVector("v5", v5);	//output: v5 = (0 0 0 0 0) -- size=5 capacity=5
	v5[1] = v5.at(3) = 9;
	printVector("v5", v5);	//output: v5 = (0 9 0 9 0)

	v3.reserve(6);	//size = 2 capacity = 6 since you are reserving 6
	printVector("v3", v3);	

	v4.resize(7);	//size = 7 capacity = 10
	printVector("v4", v4);	//output: v4 = (1 2 3 4 5 0 0)
	v4.resize(3);	//size = 3 capacity = 10
	printVector("v4", v4);	//output: v4 = (1 2 3)
	v4.clear();	 //v4 is empty, size = 0, capacity = 10
	printVector("v4", v4);	//output: v4 = ()
	v4.insert(v4.end(), v3[1]);	//takes element in index 1 and is inserted in the end of vector v4
	printVector("v4", v4);	//output: v4 = (3)
	v4.insert(v4.end(), v3.at(1));
	printVector("v4", v4);	//output: v4 = (3 3)
	v4.insert(v4.end(), 2, 4);
	printVector("v4", v4);	//output: v4 = (3 3 4 4) 
} 