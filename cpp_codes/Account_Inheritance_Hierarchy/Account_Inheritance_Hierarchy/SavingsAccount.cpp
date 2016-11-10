#include "SavingsAccount.h"
#include <iostream>

using namespace std;

SavingsAccount::SavingsAccount(double Balance, double rate): Account(Balance)
{
	balance = Balance;
    interestRate = rate;
    cout << "Rate = " << interestRate << "%" << endl;
}

double SavingsAccount::calculateInterest()
{
	return balance*(interestRate/100);
}

double SavingsAccount::setInterest(double int_rate)
{
	interestRate = int_rate;
	return interestRate;
}