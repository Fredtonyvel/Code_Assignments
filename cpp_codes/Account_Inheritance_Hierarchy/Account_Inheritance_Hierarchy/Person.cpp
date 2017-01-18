#include "Person.h"
#include <sstream>
#include <algorithm>

using namespace std;

Person::Person()
{
	fname = "No first name";
	lname = "No last name";
	location = "No Location";
	phone = "###-###-####";
}

Person::Person(string fn, string ln, string l, string p)
{
	fname = fn;
	lname = ln;
	location = l;
	phone = p;
}

Person::~Person()
{
	cout << "\nDestroying Person..." << endl;
}

void Person::setName(string fn, string ln) 
{
	fname = fn;
	lname = ln;
}
string Person::getName() {return fname + " " + lname;}

void Person::setLocation(string l) {location = l;}
string Person::getLocation() {return location;}

void Person::setPhone(string p) {phone = p;}
string Person::getPhone() {return phone;}


ostream &operator << (ostream &out, const Person &p)
{
	out << "\nName = " << p.fname << ", " << p.lname << endl;
	out << "Location = " << p.location << endl;
	out << "Phone # = " << p.phone << endl << endl;
	return out;
}

istream &operator >> (istream &in, Person &p)
{
	cin.ignore();
	cout << "\nEnter your name, location, and phone #\n";
	cout << "First name: ";
	getline(in, p.fname);
	cout << "Last name: ";
	getline(in, p.lname);
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
		file << fname << "," << lname << "|";
		file << location << "|";
		file << phone << endl;
	}

	file.close();

	cout << "\nPerson saved into the file!" << endl;
}

void Person::loadPerson()
{
	ifstream file("PersonList.txt", ios::in);
	string line, fn, ln, l, p;
	int count = 0;
	vector<string> vfname;
	vector<string> vlname;
	vector<string> vloc;
	vector<string> vpho;

	string search_name;
	cout << "Enter name you are searching for: ";
	cin >> search_name;

	if (!file.is_open())
	{
		cerr << "Failed to open file" << endl;
	}	

	while(getline(file, line))
	{
		if (line.find(search_name) != string::npos)
		{
			stringstream text(line);

			getline(text, fn, ',');
			vfname.push_back(fn);

			getline(text, ln, '|');
			vlname.push_back(ln);

			getline(text, l, '|');
			vloc.push_back(l);

			getline(text, p);
			vpho.push_back(p);

			count++;

			cout << "\n" << search_name << " found and loaded into the system!" << endl;
		}
		else
		{
			cout << search_name << " not found..." << endl;
		}
	}	

	/*while(getline(file, line))
	{
		stringstream text(line);

		getline(text, fn, ',');
		vfname.push_back(fn);

		getline(text, ln, '|');
		vlname.push_back(ln);

		getline(text, l, '|');
		vloc.push_back(l);

		getline(text, p);
		vpho.push_back(p);

		count++;
	}*/

	for (int i = 0; i < count; i++)
	{
		setName(vfname[i], vlname[i]);
		setLocation(vloc[i]);
		setPhone(vpho[i]);		
	}
	
	file.close();
}

void Person::displayPerson()
{
	cout << "\nDisplaying person:\n";
	cout << "Name = " << getName() << endl;
	cout << "Location = " << getLocation() << endl;
	cout << "Phone = " << getPhone() << endl << endl;
}