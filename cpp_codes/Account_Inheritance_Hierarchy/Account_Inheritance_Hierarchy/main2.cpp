#include <string>
#include <iostream>

#include "Person.h"

using namespace std;

int main()
{
	Person p;

	char choice;

	while(choice != 'q')
	{
		cout << "\n\t+---------[Main Menu]---------+";
		cout << "\n\t|                             |";
		cout << "\n\t|      (C)reate Person        |";
		cout << "\n\t|      (S)ave a person        |";
		cout << "\n\t|      (L)oad a person        |";
		cout << "\n\t|      (D)isplay person       |";
		cout << "\n\t|      (Q)uit program         |";
		cout << "\n\t|                             |";
		cout << "\n\t+-----------------------------+" << endl;
		
		cin >> choice;

		switch (choice)
		{
			case 'c': cin >> p; 
					  break;
			case 's': p.savePerson(); break;
			case 'l': p.loadPerson(); break;
			case 'd': p.displayPerson(); break;
			case 'q': cout << "\nHave a nice day!" << endl; break;
			default : cout << "Please choose a valid option!\n";
		}
	}

	return 0;
}
