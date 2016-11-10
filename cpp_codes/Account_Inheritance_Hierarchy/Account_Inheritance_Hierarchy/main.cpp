#include <iostream>
#include "Account.h"
#include "SavingsAccount.h"

using namespace std;

int main()
{
    cout << "Welcome to the Account Inheritance Hierarchy!\n";

    Account obj(2.50);
    obj.printBalance(obj.getBalance());

    cout << "New balance: $" << obj.credit(2.50) << endl;
    obj.printBalance(obj.getBalance());

    obj.debit(6);
    obj.printBalance(obj.getBalance());

    obj.setBalance(10.50);
    obj.printBalance(obj.getBalance());

    SavingsAccount obj2(obj.getBalance(), 2);
    obj2.printBalance(obj2.getBalance());

    cout << obj2.calculateInterest() << endl;

    cout << "Resetting interest rate...\n";
    cout << "Rate = " << obj2.setInterest(5) << "%" << endl;

    return 0;
}
