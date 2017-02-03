#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <iostream>
#include <string>

using namespace std;

class Professor
{
public:
	Professor();
	Professor(string, string, string, string, string);
	~Professor();

	string getFirstName();
	string getLastName();
	string getRoomNum();
	string getEmail();
	string getPhone();
	void printProf();

	friend ostream &operator << (ostream &out, const Professor &p);
	friend istream &operator >> (istream &in, Professor &p);

private:
	string firstName;
	string lastName;
	string room;
	string email;
	string phone;
};

#endif /* PROFESSOR_H */