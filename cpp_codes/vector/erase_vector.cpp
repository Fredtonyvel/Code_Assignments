#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
	int num;
	cin >> num;
	vector<int> n(num);
	for (int i = 0; i < n.size(); ++i)
	{
		cin >> n[i];
	}

	int pos, range1, range2;
	cin >> pos;
	n.erase(n.begin()+(pos-1));
	cout << n.size() << endl;
	for(auto &i : n)
	{
		cout << i << " ";
	}
	cout << endl;
	
	cin >> range1 >> range2;
	n.erase(n.begin()+(range1-1), n.begin()+(range2-1));
	cout << n.size() << endl;
	for(auto &i : n)
	{
		cout << i << " ";
	}
	cout << endl;

	return 0;
}