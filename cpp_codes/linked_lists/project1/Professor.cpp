#include "Professor.h"

using namespace std;

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
	lastName = ln;
	firstName = fn;
	room = rn;
	email = e;
	phone = pn;
}

Professor::~Professor()
{
	//cout << "\nDeleting Professor information..." << endl;
}

void Professor::setFirstName(string fn)
{
	firstName = fn;
}

void Professor::setLastName(string ln)
{
	lastName = ln;
}

void Professor::setRoomNum(string rn)
{
	room = rn;
}

void Professor::setEmail(string em)
{
	email = em;
}

void Professor::setPhone(string ph)
{
	phone = ph;
}

string Professor::getFirstName() const
{
	return firstName;
}

string Professor::getLastName() const
{
	return lastName;
}

string Professor::getRoomNum() const
{
	return room;
}

string Professor::getEmail() const
{
	return email;
}

string Professor::getPhone() const
{
	return phone;
}

void Professor::printProf()
{
	cout << "------------------------------\n";
	cout << "  Name: " << lastName << ", " << firstName << endl;
	cout << "  Room #: " << room << endl;
	cout << "  Email: " << email << endl;
	cout << "  Phone #: " << phone << endl;
	cout << "------------------------------\n";
}

ostream &operator << (ostream &out, const Professor &p)
{
	out << "Professor Name: " << p.lastName << " " << p.firstName << endl;
	out << "Office Room #: " << p.room << endl;
	out << "Email: " << p.email << endl;
	out << "Phone #: " << p.phone << endl;
	return out;
}

istream &operator >> (istream &in, Professor &p)
{
	cout << "Enter Professor first and last name: ";
	in >> p.firstName >> p.lastName;
	cout << "Enter Room #: ";
	in >> p.room;
	cout << "Enter email address: ";
	in >> p.email;
	cout << "Enter phone #: ";
	in >> p.phone;
	return in;
}