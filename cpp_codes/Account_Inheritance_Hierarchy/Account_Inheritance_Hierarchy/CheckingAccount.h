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

    //friend ostream& operator << (ostream &out, CheckingAccount &obj);
    //friend istream& operator >> (istream &in, CheckingAccount &obj);

};

#endif // CHECKINGACCOUNT_H_INCLUDED