#include <string>
#include <iostream>

using namespace std;

#include "Professor.h"

Professor::Professor()
{
	firstName = "--";
	lastName = "--";
	room = "--";
	email = "--";
	phone = "--";	
}

Professor::Professor(string fn, string ln, string rn, string e, string pn)
{
	firstName = fn;
	lastName = ln;
	room = rn;
	email = e;
	phone = pn;
}

Professor::~Professor()
{
	cout << "\nDeleting Professor information..." << endl;
}

string Professor::getFirstName()
{
	return firstName;
}

string Professor::getLastName()
{
	return lastName;
}

string Professor::getRoomNum()
{
	return room;
}

string Professor::getEmail()
{
	return email;
}

string Professor::getPhone()
{
	return phone;
}

void Professor::printProf()
{
	cout << "Professor name: " << firstName << ", " << lastName << endl;
	cout << "Office location: " << room << endl;
	cout << "Email: " << email << endl;
	cout << "Contact number: " << phone << endl;
}