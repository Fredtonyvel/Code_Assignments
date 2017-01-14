#include "Person.h"
#include <sstream>

using namespace std;

Person::Person()
{
	name = "No name";
	location = "No Location";
	phone = "###-###-####";
}

Person::Person(string n, string l, string p)
{
	setName(n);
	setLocation(l);
	setPhone(p);
}

Person::~Person()
{
	cout << "\nDestroying Person..." << endl;
}

void Person::setName(string n) {name = n;}
string Person::getName() {return name;}

void Person::setLocation(string l) {location = l;}
string Person::getLocation() {return location;}

void Person::setPhone(string p) {phone = p;}
string Person::getPhone() {return phone;}


ostream &operator << (ostream &out, const Person &p)
{
	out << "\nName = " << p.name << endl;
	out << "Location = " << p.location << endl;
	out << "Phone # = " << p.phone << endl << endl;
	return out;
}

istream &operator >> (istream &in, Person &p)
{
	cin.ignore();
	cout << "\nEnter your name, location, and phone #\n";
	cout << "Name (first, last): ";
	getline(in, p.name);
	cout << "Location (City, State): ";
	getline(in, p.location);
	cout << "Phone (###-###-####): ";
	getline(in, p.phone);
	return in;
}

void Person::savePerson()
{
	ofstream file("PersonList.txt", ios::out | ios::app);
	if (file.is_open())
	{
		file << name << endl;
		file << location << endl;
		file << phone << endl << endl;
	}

	file.close();

	cout << "\nPerson saved into the file!" << endl;
}

void Person::loadPerson()
{
	ifstream file("PersonList.txt", ios::in);
	string line, n, l, p;
	if (file.is_open())
	{
		while(!file.eof())
		{
			cin.ignore();
			getline(file, n);
			getline(file, l);
			getline(file, p);
			
			setName(n);
			setLocation(l);
			setPhone(p);
		}
	}
	file.close();
	
	cout << "\nPerson loaded into the system!" << endl;
}

void Person::displayPerson()
{
	cout << "\nDisplaying person:\n";
	cout << "Name = " << getName() << endl;
	cout << "Location = " << getLocation() << endl;
	cout << "Phone = " << getPhone() << endl << endl;
}