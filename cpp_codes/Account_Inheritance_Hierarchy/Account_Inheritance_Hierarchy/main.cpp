#include <iostream>
#include "Account.h"

using namespace std;

int main()
{
    cout << "Welcome to the Account Inheritance Hierarchy!\n\n";

    Account obj(2.50);
    obj.getBalance();
    int credit = obj.credit(2.50);
    cout << "New balance: $" << credit << endl;
    obj.getBalance();
    obj.debit(5);
    obj.getBalance();

    obj.setBalance(10.50);
    obj.getBalance();

    return 0;
}
