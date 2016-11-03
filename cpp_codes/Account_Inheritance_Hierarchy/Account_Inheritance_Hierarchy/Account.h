#ifndef ACOUNT_H_INCLUDED
#define ACOUNT_H_INCLUDED
#include <iostream>

class Account
{
private:
    double balance;

public:
    Account(double);
    double credit(double);
    bool debit(double);
    void getBalance();
    void setBalance(double);
};

#endif // ACOUNT_H_INCLUDED
