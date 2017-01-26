#include "Account.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <time.h>

using namespace std;

void Menu()
{
    cout << "\nChoose from the following:\n";
    cout << "1. Deposit\n";
    cout << "2. Withdraw\n";
    cout << "3. Set balance\n";
    cout << "4. Print balance\n";
    cout << "5. Exit\n\n";
}

int main()
{
    cout << "Welcome User!\n";

    time_t rawtime;

    time(&rawtime);
    cout << "Local time is: " << ctime(&rawtime);
    

    ofstream file("User.txt", ios_base::app | ios_base::out);

    if (file.is_open())
    {
        file << "---    Transaction History    ---" << endl;
        file << "\nLocal time is: " << ctime(&rawtime);
        
        double balance;
        cout << "\nEnter balance for your account\n";
        cin >> balance;
        file << fixed << setprecision(2) << "\tBalance for the account = $" << balance << endl;
        Account obj1(balance);

        char select;
        cout << "\nWould you to start your transaction?\n";
        cout << "Enter 'y' for yes\nEnter 'n' for no\n";
        cin >> select;

        do
        {
            if (select == 'y')
            {
                Menu();
                cout << "Select Number: ";
                int choice;
                cin >> choice;
                cout << endl;

                switch(choice)
                {
                    case 1: double credit;
                            cout << "Enter the amount of credit\n";
                            cin >> credit;
                            obj1.credit(credit);
                            file << "\nLocal time is: " << ctime(&rawtime);
                            file << "\tAmount of credit added to account = " << credit << endl;
                            file << "\tBalance = " << obj1.getBalance() << endl;
                            break;

                    case 2: double debit, c;
                            cout << "Enter the amount of debit\n";
                            cin >> debit;
                            c = obj1.debit(debit);
                            if (c == true)
                            {
                                file << "\nLocal time is: " << ctime(&rawtime);
                                file << "\tAmount withdrawn from account = " << debit << endl;
                                file << "\tBalance = " << obj1.getBalance() << endl;
                            }
                            else
                            {
                                file << "\nLocal time is: " << ctime(&rawtime);
                                file << "\tAmount attempted to be withdrawn from account = " << debit << endl;
                                file << "\tError processing transaction since debit amount exceeds balance" << endl; 
                                file << "\tBalance = " << obj1.getBalance() << endl;
                            }
                            break;


                    case 3: double setBalance;
                            cout << "Enter amount to reset your balance\n";
                            cin >> setBalance;
                            if (setBalance < 0)
                            {
                                file << "\nLocal time is: " << ctime(&rawtime);
                                file << "\tThe amount entered to reset balance was less than 0\n";
                                file << "\tBalance automatically reset to 0\n";
                                obj1.setBalance(setBalance);
                                file << "\tBalance = " << obj1.getBalance() << endl;
                            }
                            else
                            {
                                obj1.setBalance(setBalance);
                                file << "\nLocal time is: " << ctime(&rawtime);
                                file << "\tAmount to reset account = " << setBalance << endl;
                                file << "\tBalance = " << obj1.getBalance() << endl;
                            }
                            break;

                    case 4: cout << fixed << setprecision(2);
                            cout << "---\tCurrent balance in your account = $"
                                 << obj1.getBalance() << "\t---" << endl;
                            break;

                    case 5: select = 'n';
                            break;               

                    default: cout << "!!!\tPlease select a number\t!!!\n";
                }
            }   
        } while (select != 'n' && select == 'y');  

        cout << "\nExiting System\t---\tHave a nice day!\n\n";
        file << "\n---    End of History    ---\n\n";
    }

    file.close();

    return 0;
}


    /*CheckingAccount obj3(obj.getBalance(), 5.50);
    obj3.printFee();

    if (obj3.chargeFee())
    {
        cout << "---\tFee has been charged\t---" << endl;
        obj3.printFee();
        obj3.printBalance();
    }
    else
    {
        cout << "---\tFee has not been charged\t---" << endl;
        obj3.printFee();
        obj3.printBalance();
    }*/