#include <iostream>
#include "Account.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"

using namespace std;

int main()
{
    cout << "Welcome to the Account Inheritance Hierarchy!\n";

    double balance;
    cout << "\nEnter balance for your account\n";
    cin >> balance;
    Account obj1(balance);

    char select;
    cin >> select;

    do
    {
        cout << "\nChoose from the following:\n";
        cout << "1. Account balance\n";
        cout << "2. Credit\n";
        cout << "3. Debit\n";
        cout << "4. Set balance\n";
        cout << "5. Print balance\n\n";

        int choice;
        cin >> choice;

        switch(choice)
        {
            /*case 1: int balance;
                      cout << "Enter balance for your account\n";
                      cin >> balance;
                      Account obj1(balance);
                      break;*/

            case 2: int credit;
                    cout << "Enter the amount of credit\n";
                    cin >> credit;
                    obj1.credit(credit);
                    break;

            case 3: int debit;
                    cout << "Enter the amount of debit\n";
                    cin >> debit;
                    obj1.debit(debit);
                    break;

            case 4: int setBalance;
                    cout << "Enter amount to reset yout balance\n";
                    cin >> setBalance;
                    obj1.setBalance(setBalance);
                    break;

            case 5: cout << fixed << setprecision(2);
                    cout << "---\tCurrent balance in your account = "
                         << obj1.getBalance() << "\t---" << endl;
                    break;

            default: cout << "!!!\tPlease select a number\t!!!\n";
        }

        cout << "\nPress 'y' to continue\n";
        cin >> select;
    } while (select == 'y');
    

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

    return 0;
}
