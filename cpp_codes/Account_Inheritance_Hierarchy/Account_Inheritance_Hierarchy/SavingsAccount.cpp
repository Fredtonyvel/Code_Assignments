#include "SavingsAccount.h"
#include <iostream>
#include <fstream>
#include <string>
#include <regex>

using namespace std;

SavingsAccount::SavingsAccount() : Account()
{
	interestRate = 0;
}

SavingsAccount::SavingsAccount(double Balance, double rate): Account(Balance)
{
	balance = Balance;
    interestRate = rate;
    cout << "Rate = " << interestRate << "%" << endl;
}

double SavingsAccount::calculateInterest()
{
	interest = balance*(interestRate/100);
	return interest;
}

double SavingsAccount::setInterest(double int_rate)
{
	interestRate = int_rate;
	return interestRate;
}

double SavingsAccount::getInterest()
{
	return interestRate;
}

void SavingsAccount::printRate()
{
	cout << "---\tCurrent Interest Rate = " 
		 << getInterest() << "%\t---" << endl;
}