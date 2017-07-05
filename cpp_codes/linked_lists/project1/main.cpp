#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <sstream>
#include <iomanip>


#include "Professor.h"
#include "list.h"

using namespace std;


static int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
    for(int i = 0; i<argc; i++)
    {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    cout << endl;

    return 0;
}

int main(int argc, char* argv[])
{
	cout << "John Jay College of Criminal Justice Professor Database" << endl;
	char select;
	int choice;

	Professor prof;
	list ll;
	string fname, lname;

	while(select != 'q')
	{
		cout << "\n\nSelect # from the menu" << endl;
		cout << "'1' - Add Professor\n";
		cout << "'2' - Delete Professor\n";
		cout << "'3' - Search Professor\n";
		cout << "'4' - Display\n";
		cout << "'5' - Save data to database\n";
		cout << "'6' - Load data from database\n";
		cout << "'7' - Exit\n\n";

		cout << "Enter number: ";
		cin >> choice;
		cout << endl;
		
		switch(choice)
		{
			case 1 : cin >> prof;
				     ll.insert(prof);
				     break;

			case 2 : //Will be implemented soon
					 break;

			case 3 : cout << "Enter first name and then press enter to enter last name\n";
					 cout << "First Name: ";
					 cin >> fname;
					 cout << "Last Name: ";
					 cin >> lname;
					 cout << ll.search(fname, lname) << endl;
					 break;

			case 4 : ll.display();
					 break;

			case 5 : ll.save();
					 break;

			case 6 : ll.load();
					 break;

			case 7 : select = 'q';
					 cout << "Goodbye!\n";
					 break;

			default : cout << "Number entered invalid!!" << endl;
					  break;
		}

	}

	/*Professor s("Tony", "Doe", "5.63NB", "tonydoe@aol.com", "646-555-2697");
	Professor m("Jane", "Dane", "6.63NB", "janedane@aol.com", "917-654-7891");
	Professor d("Karen", "Page", "7.63NB", "karenpage@aol.com", "347-239-4675");
	Professor f("Bruce", "Allen", "10.63NB", "bruceallen@aol.com", "718-693-3348");
	Professor g("Freddy", "Velez", "9.63NB", "freddyvelez@aol.com", "347-754-6251");
	Professor h("Anthony", "Velez", "4.63NB", "anthonyvelez@aol.com", "347-154-7251");
	Professor i("Kenneth", "Cole", "8.63NB", "kennethcole@aol.com", "718-583-2236");

	list ll;
	ll.insert(s);
	ll.insert(m);
	ll.insert(d);
	ll.insert(f);
	ll.insert(g);
	ll.insert(h);
	ll.insert(i);
	ll.display();
	ll.save();
	ll.load();*/
	//cout << "\nSize of professor list: " << ll.size() << endl;

	/*string fname, lname;
	cout << "Enter first name and then press enter to enter last name\n";
	cout << "First Name: ";
	cin >> fname;
	cout << "Last Name: ";
	cin >> lname;
	cout << ll.search(fname, lname) << endl;*/

	/*sqlite3 *db;
	char *zErrMsg = 0;
	int rc;

	//Opening database
	rc = sqlite3_open("test.db", &db);

	if(rc)
	{
		cout << "Can't open database" << sqlite3_errmsg(db) << endl;
		return 0;
	}	
	else
		cout << "Opened database successfully" << endl;

	//Create SQL statement
	const char *sql;
	sql = "CREATE TABLE IF NOT EXISTS JJAY("	\
		  "ID INT PRIMARY		KEY			NOT NULL,"	\
		  "LAST_NAME			TEXT		NOT NULL,"	\
		  "FIRST_NAME			TEXT		NOT NULL,"	\
		  "OFFICE_NO			TEXT		NOT NULL,"	\
		  "EMAIL 				CHAR(70),"	\
		  "PHONE_NO				CHAR(15));";

	//Executing SQL statement
	rc = sqlite3_exec(db, sql, 0, 0, &zErrMsg);

	if(rc != SQLITE_OK)
	{
		cout << "SQL error: " << zErrMsg << endl;
	 	sqlite3_free(zErrMsg);
	}
	else
		cout << "Table created successfully" << endl;


	//Inserting values into Table

	/*Professor * profArray[7];
	profArray[0] = new Professor("Tony", "Doe", "5.63NB", "tonydoe@aol.com", "646-555-2697");
	profArray[1] = new Professor("Jane", "Dane", "6.63NB", "janedane@aol.com", "917-654-7891");
	profArray[2] = new Professor("Karen", "Page", "7.63NB", "karenpage@aol.com", "347-239-4675");
	profArray[3] = new Professor("Bruce", "Allen", "10.63NB", "bruceallen@aol.com", "718-693-3348");
	profArray[4] = new Professor("Freddy", "Velez", "9.63NB", "freddyvelez@aol.com", "347-754-6251");
	profArray[5] = new Professor("Anthony", "Velez", "4.63NB", "anthonyvelez@aol.com", "347-154-7251");
	profArray[6] = new Professor("Kenneth", "Cole", "8.63NB", "kennethcole@aol.com", "718-583-2236");*/
	
	/*string sql2[7];
	const char *sql2Stmt;


	for(int i = 0; i < 7; i++)
	{	
		//cin >> profArray[i];

		sql2[i] = "INSERT INTO JJAY(ID, LAST_NAME, FIRST_NAME, OFFICE_NO, EMAIL, PHONE_NO) " \
		                   "VALUES (" + to_string(i+1) + ", '" 
		               	             + profArray[i]->getLastName().c_str() + "', '"
		               	             + profArray[i]->getFirstName().c_str() + "', '"
		               	             + profArray[i]->getRoomNum().c_str() + "', '"
		               	             + profArray[i]->getEmail().c_str() + "', '"
		               	             + profArray[i]->getPhone().c_str() + "');";
		sql2Stmt = sql2[i].c_str();
	
		rc = sqlite3_exec(db, sql2Stmt, 0, 0, &zErrMsg);
		if( rc != SQLITE_OK )
		{
			cout << "SQL error: " << zErrMsg << endl;
			sqlite3_free(zErrMsg);
		} 
		else
			cout << "Record created successfully" << endl << endl;
	}

	//Select * From Table
	const char *sql3 = "SELECT * from JJAY";
	//const char * data = "Callback function called";

	rc = sqlite3_exec(db, sql3, callback, 0, &zErrMsg);
	if( rc != SQLITE_OK )
	{
		cout << "SQL error: " << zErrMsg << endl;
		sqlite3_free(zErrMsg);
	} 
	else
		cout << "Operation done successfully" << endl;

	sqlite3_close(db);*/

	/*sqlite3 *db;
	char *zErrMsg = 0;
	int rc;

	//Opening database
	rc = sqlite3_open("test.db", &db);

	if(rc)
	{
		cout << "Can't open database" << sqlite3_errmsg(db) << endl;
		return 0;
	}	
	else
		cout << "Opened database successfully" << endl;

	//Create SQL statement
	string sql;
	while(sql != "quit")
	{
		getline(cin,sql);

		//Executing SQL statement
		rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
		if(rc != SQLITE_OK)
		{
			cout << "SQL error: " << zErrMsg << endl;
		 	sqlite3_free(zErrMsg);
		}
		else
			cout << "Operation done successfully" << endl;
	}

	sqlite3_close(db);*/

	return 0;
}