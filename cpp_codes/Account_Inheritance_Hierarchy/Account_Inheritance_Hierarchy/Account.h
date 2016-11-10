#ifndef ACOUNT_H_INCLUDED
#define ACOUNT_H_INCLUDED
#include <iostream>
#include <iomanip>

class Account
{
protected:
    double balance;

public:
    Account(double);
    double credit(double);
    bool debit(double);
    void getBalance();
    void setBalance(double);
};

#endif // ACOUNT_H_INCLUDED
