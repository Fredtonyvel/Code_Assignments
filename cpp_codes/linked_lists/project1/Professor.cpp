#include <string>
#include <iostream>

using namespace std;

#include "Professor.h"

Professor::Professor(string first, string last, string rmNum, string email, string phNum)
{
	firstName = first;
	lastName = last;
	roomNum = rmNum;
	emailInfo = email;
	phoneNum = phNum;
}

Professor::~Professor()
{
	cout << "\nDeleting Professor information..." << endl;
}

void Professor::printProf()
{
	cout << "Professor name: " << firstName << ", " << lastName << endl;
	cout << "Office location: " << roomNum << endl;
	cout << "Email: " << emailInfo << endl;
	cout << "Contact number: " << phoneNum << endl;
}