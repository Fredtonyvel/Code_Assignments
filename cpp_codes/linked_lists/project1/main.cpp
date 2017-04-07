#include <string>
#include <iostream>

#include "Professor.h"
#include "list.h"

using namespace std;

int main()
{
	Professor s("Anthony", "Velez", "5.15NB", "vfredanthony@yahoo.com", "347-813-6946");
	Professor m("Angelica", "Velez", "6.63NB", "a_vele@hotmail.com", "347-239-1576");
	Professor d("Emely", "Velez", "7.63NB", "emely_vele@gmail.com", "347-239-4675");
	Professor f("Freddy", "Velez", "10.63NB", "f_velez@gmail.com", "347-528-0598");

	list ll;
	ll.addNode(s,23);
	ll.addNode(m,1);
	ll.addNode(d,14);
	ll.addNode(f,0);
	//cout << "Size = " << ll.size() << endl;
	ll.print();

	/*string fname, lname;
	cout << "Enter first name and then press enter to enter last name\n";
	cout << "First Name: ";
	cin >> fname;
	cout << "Last Name: ";
	cin >> lname;
	cout << ll.search(fname, lname) << endl;*/

	return 0;
}