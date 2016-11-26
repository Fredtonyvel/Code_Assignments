#include "Account.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include <iostream>
#include <fstream>
#include <iomanip>

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
    cout << "Welcome to the Account Inheritance Hierarchy!\n";

    ofstream file("User.txt", ios_base::app | ios_base::out);

    if (file.is_open())
    {
        double balance;
        cout << "\nEnter balance for your account\n";
        cin >> balance;
        file << fixed << setprecision(2)
             << "Balance for the account = $" << balance << endl;
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

                int choice;
                cin >> choice;

                switch(choice)
                {
                    case 1: double credit;
                            cout << "Enter the amount of credit\n";
                            cin >> credit;
                            obj1.credit(credit);
                            file << "\nAmount of credit added to account = $" << credit << endl;
                            file << "New balance = $" << obj1.getBalance() << endl;
                            break;

                    case 2: double debit;
                            cout << "Enter the amount of debit\n";
                            cin >> debit;
                            obj1.debit(debit);
                            if (obj1.debit(debit) == true)
                            {
                                file << "\nAmount withdrawn from account = $" << debit << endl;
                                file << "New balance = $" << obj1.getBalance() << endl;
                                break;
                            }
                            else
                            {
                                file << "\nAmount attempted to be withdrawn from account = $" << debit << endl;
                                file << "Error processing transaction since debit amount exceeds balance\n"; 
                                break;
                            }


                    case 3: double setBalance;
                            cout << "Enter amount to reset your balance\n";
                            cin >> setBalance;
                            obj1.setBalance(setBalance);
                            file << "\nAmount to reset account = $" << setBalance << endl;
                            file << "New balance = $" << obj1.getBalance() << endl;
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

        cout << "\n\nExiting System\t---\tHave a nice day!\n\n";
    }

    file.close();

    return 0;
}



/*Account obj(2.50);
    obj.printBalance();

    cout << "New balance: $" << obj.credit(2.50) << endl;
    obj.printBalance();

    obj.debit(6);
    obj.printBalance();

    obj.setBalance(10.50);
    obj.printBalance();

    SavingsAccount obj2(obj.getBalance(), 2);
    obj2.printBalance();

    cout << obj2.calculateInterest() << endl;

    cout << "Resetting interest rate...\n";
    cout << "Rate = " << obj2.setInterest(5) << "%" << endl;

    obj2.printRate();

    CheckingAccount obj3(obj.getBalance(), 5.50);
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