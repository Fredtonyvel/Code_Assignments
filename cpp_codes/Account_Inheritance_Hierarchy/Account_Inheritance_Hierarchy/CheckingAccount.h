#ifndef CHECKINGACCOUNT_H_INCLUDED
#define CHECKINGACCOUNT_H_INCLUDED
#include "Account.h"
#include <iostream>

class CheckingAccount : public Account
{
private:
    double fee;

public:
    CheckingAccount(double, double);
    bool chargeFee();
    double setFee(double);
    double getFee();
    void printFee();

};

#endif // CHECKINGACCOUNT_H_INCLUDED