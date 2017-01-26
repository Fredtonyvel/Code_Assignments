#ifndef SAVINGSACCOUNT_H_INCLUDED
#define SAVINGSACCOUNT_H_INCLUDED
#include "Account.h"
#include <iostream>

class SavingsAccount : public Account
{
private:
    double interestRate;
    double interest;
    
public:
	SavingsAccount();
    SavingsAccount(double, double);
    double calculateInterest();
    double setInterest(double);
    double getInterest();
    void printRate();

    void loadBalance();
    void viewHistory();
};

#endif // SAVINGSACCOUNT_H_INCLUDED
