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

    double interest;
    cout << "\nSet the interest for your account\n";
    cin >> interest;
    SavingsAccount obj2(balance, interest);

    char select;
    cout << "\nWould you to start your transaction?\n";
    cout << "Enter 'y' for yes\nEnter 'n' for no\n";
    cin >> select;

    do
    {
        if (select == 'y')
        {
            cout << "\nChoose from the following:\n";
            cout << "1. Credit\n";
            cout << "2. Debit\n";
            cout << "3. Set balance\n";
            cout << "4. Print balance\n";
            cout << "5. Add Interest\n";
            cout << "6. Set Interest\n";
            cout << "7. Print Interest\n";
            cout << "8. Exit\n\n";

            int choice;
            cin >> choice;

            switch(choice)
            {
                case 1: int credit;
                        cout << "Enter the amount of credit\n";
                        cin >> credit;
                        obj1.credit(credit);
                        break;

                case 2: int debit;
                        cout << "Enter the amount of debit\n";
                        cin >> debit;
                        obj1.debit(debit);
                        break;

                case 3: int setBalance;
                        cout << "Enter amount to reset yout balance\n";
                        cin >> setBalance;
                        obj1.setBalance(setBalance);
                        break;

                case 4: cout << fixed << setprecision(2);
                        cout << "---\tCurrent balance in your account = "
                             << obj1.getBalance() << "\t---" << endl;
                        break;

                case 5: double c; 
                        c = obj2.calculateInterest();
                        obj2.credit(c);
                        break;

                case 8: select = 'n';
                        break;               

                default: cout << "!!!\tPlease select a number\t!!!\n";
            }
        }   

    } while (select != 'n' && select == 'y');

    cout << "\n\nExiting System\t---\tHave a nice day!\n\n";
    

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
