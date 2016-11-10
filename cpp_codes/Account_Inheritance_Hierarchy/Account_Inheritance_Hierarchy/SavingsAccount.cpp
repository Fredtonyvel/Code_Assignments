#include "SavingsAccount.h"
#include <iostream>

using namespace std;

SavingsAccount::SavingsAccount(double Balance, double rate): Account(Balance)
{
    interestRate = rate;
    cout << interestRate << "%" << endl;
}
