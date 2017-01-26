#ifndef ACOUNT_H_INCLUDED
#define ACOUNT_H_INCLUDED
#include <iostream>
#include <iomanip>

class Account
{
protected:
    double balance;

public:
	Account();
    Account(double);
    double credit(double);
    bool debit(double);
    double getBalance();
    void setBalance(double);
    void printBalance();

    //friend ostream& operator << (ostream &out, Account &obj);
    //friend istream& operator >> (istream &in, Account &obj);
};

#endif // ACOUNT_H_INCLUDED