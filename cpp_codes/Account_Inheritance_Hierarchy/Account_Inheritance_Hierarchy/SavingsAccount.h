#ifndef SAVINGSACCOUNT_H_INCLUDED
#define SAVINGSACCOUNT_H_INCLUDED
#include "Account.h"
#include <iostream>

class SavingsAccount : public Account
{
private:
    double interestRate;

public:
    SavingsAccount(double, double);
};

#endif // SAVINGSACCOUNT_H_INCLUDED
