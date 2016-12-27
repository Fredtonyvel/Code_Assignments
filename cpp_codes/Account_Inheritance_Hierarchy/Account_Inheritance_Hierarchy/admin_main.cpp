#include "Account.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <stdio.h>
#include <time.h>
#include <regex>

using namespace std;

void Menu()
{
    cout << "\nChoose from the following:\n";
    cout << "1. Credit\n";
    cout << "2. Debit\n";
    cout << "3. Set balance\n";
    cout << "4. Print balance\n";
    cout << "5. Exit\n\n";
}

int main()
{
    //cout << "Welcome to the Account Inheritance Hierarchy!\n";
    cout << "Welcome Admin!\n\n";

    time_t rawtime;

    time(&rawtime);
    //cout << "Local time is: " << ctime(&rawtime);

    ifstream file("User.txt");
    string line;
    int count = 0;
    ofstream file2("User.txt", ios_base::app | ios_base::out);

    if (file.is_open() && file2.is_open())
    {   
        //double balance;
        //cout << "\nEnter balance for your account\n";
        //cin >> balance;
        //file << fixed << setprecision(2) << "\tBalance for the account = $" << balance << endl;
        //Account obj1(balance);

        while(getline(file, line))
        {
            //cout << line <<  endl; 

            for (int i = 0; i < line.length(); i++)
            {
                count++;
            }
        }
        cout << "\nNumber of characters in the text file: " << count << endl;
        //cout << endl;
    }

    file.close();
    file2.close();

    return 0;
}

        /*double rate;
        cout << "Enter interest for the account:";
        cin >> rate;
        SavingsAccount obj_admin(obj1.getBalance(), rate);
        obj_admin.calculateInterest();
        obj_admin.getBalance();
        */