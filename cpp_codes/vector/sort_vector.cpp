#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <algorithm>

using namespace std;

void sortVector(vector<int> N)
{
	sort(N.begin(), N.end());

	for(auto &x : N)
	{
		cout << x << " ";
	}
	cout << endl;
}

int	main()
{
	int num;
	cin >> num;
	vector<int> N(num);

	for (int i = 0; i < N.size(); i++)
	{
		cin >> N[i];
	}

	sortVector(N);

	return 0;
}