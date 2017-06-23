#include <string>
#include <iostream>

#include "Professor.h"
#include "list.h"

using namespace std;

int main()
{
	Professor s("Tony", "Doe", "5.15NB", "tonydoe@aol.com", "646-555-2697");
	Professor m("Jane", "Dane", "6.63NB", "janedane@aol.com", "917-654-7891");
	Professor d("Karen", "Page", "7.63NB", "karenpage@aol.com", "347-239-4675");
	Professor f("Bruce", "Allen", "10.63NB", "bruceallen@aol.com", "718-693-3348");
	Professor g("Freddy", "Velez", "6.63NB", "freddyvelez@aol.com", "347-754-6251");
	Professor h("Anthony", "Velez", "6.63NB", "anthonyvelez@aol.com", "347-154-7251");

	list ll;
	ll.insert(s);
	ll.insert(m);
	ll.insert(d);
	ll.insert(f);
	ll.insert(g);
	ll.insert(h);
	cout << "Size of professor list: " << ll.size() << endl;
	ll.print();

	string fname, lname;
	cout << "Enter first name and then press enter to enter last name\n";
	cout << "First Name: ";
	cin >> fname;
	cout << "Last Name: ";
	cin >> lname;
	cout << ll.search(fname, lname) << endl;

	return 0;
}