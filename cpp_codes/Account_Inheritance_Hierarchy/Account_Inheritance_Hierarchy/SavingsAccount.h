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
    double calculateInterest();
    double setInterest(double);
    double getInterest();
    void printRate();

    friend ostream& operator << (ostream &out, Account &obj);
    friend istream& operator >> (istream &in, Account &obj);

};

#endif // SAVINGSACCOUNT_H_INCLUDED
