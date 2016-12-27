#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main()
{
	string s1("$1000.00");

	regex r("\'$\'d*\'.\'d{2}");

	if (regex_match(s1, r))
	{
		cout << "ok" << endl;
	}
	else
	{
		cout << "no" <<  endl;
	}

	return 0;
}