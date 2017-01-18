#ifndef PERSON_H
#define PERSON_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person
{
public:
	Person();
	Person(string, string, string, string);
	~Person();

	friend ostream &operator << (ostream &out, const Person &p);
	friend istream &operator >> (istream &in, Person &p);

	void setName(string, string);
	string getName();
	void setLocation(string);
	string getLocation();
	void setPhone(string);
	string getPhone();

	void savePerson();
	void loadPerson();
	void displayPerson();

private:
	string fname, lname;
	char gender;
	int age;
	string dateOfBirth;
	string location;
	string phone;
};

#endif // PERSON_H