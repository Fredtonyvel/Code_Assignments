#include "Account.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <time.h>
#include <regex>

using namespace std;

void Menu()
{
    cout << "\nChoose from the following:\n";
    cout << "1. Load balance\n";
    cout << "2. View History\n";
    cout << "3. Calculate interest\n"; 
    cout << "4. Print rate\n";
    cout << "5. Print balance\n";
    cout << "6. Set interest\n";
    cout << "7. Exit\n\n";
}

int main()
{
    cout << "Welcome Admin!\n\n";

    SavingsAccount obj;

    //time_t rawtime;

    //time(&rawtime);
    //cout << "Local time is: " << ctime(&rawtime);


    cout << "\nEnter 'y' to activate system\n";
    cout << "Enter 'n' to exit\n";

    char select;
    cout << "Select: ";
    cin >> select;
    
    do
    {
        if (select == 'y')
        {
            Menu();
            int choice;
            cout << "Choice: ";
            cin >> choice;

            switch(choice)
            {
                case 1: obj.loadBalance(); break;
                case 2: obj.viewHistory(); break;
                case 3: cout << "Calculated interest = $" << obj.calculateInterest() << endl; break;
                case 4: cout << "Interest rate = " << obj.getInterest() << "%" << endl; break;
                case 5: cout << "Balance = $" << obj.getBalance() << endl; break;
                case 6: double r;
                        cout << "Set new rate: ";
                        cin >> r;
                        obj.setInterest(r);
                        break;    
                case 7: select = 'n'; break;
                default: cout << "Pleace select a number!" << endl;
            }
        }
    } while (select == 'y' && select != 'n');

    cout << "\nExiting System\t---\tHave a nice day!\n\n";
    //cout << "\nNumber of characters in the text file: " << count << endl << endl;       

    return 0;
}