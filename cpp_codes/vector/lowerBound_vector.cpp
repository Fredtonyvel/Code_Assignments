#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <iostream>

using namespace std;

void printVector(vector<int> v)
{
	for(auto &x : v)
	{
		cout << x << " ";
	}
	cout << endl;
}

int main()
{
	int num;
	cin >> num;
	vector<int> n(num);

	for (int i = 0; i < n.size(); ++i)
	{
		cin >> n[i];
	}

	sort(n.begin(), n.end());
	//printVector(n);

	int queries;
	cin >> queries;

	vector<int>::iterator low;
	for (int j = 0; j < queries; j++)
	{
		low = lower_bound(n.begin(), n.end(), 20);
		cout << "Lower bound at position: " << (low - n.begin()) << endl;
	}

	return 0;
}