#include <iostream>
#include "Account.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"

using namespace std;

int main()
{
    cout << "Welcome to the Account Inheritance Hierarchy!\n";

    Account obj(2.50);
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
    }

    return 0;
}
