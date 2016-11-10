#include "Account.h"

using namespace std;

//Constructor that initializes data member to
//parameter's value and checks if value > 0
Account::Account(double Balance)
{
    balance = Balance;
    //To print balance with trailing zeros
    cout << fixed << setprecision(2);
    if(Balance > 0)
    {
        //cout << fixed << setprecision(2);
        cout << "\nBalance = $" << balance << endl;
    }
    else
    {
        balance = 0;
        cout << "!!!\tError\t!!!\n";
        cout << "Balance not more than zero!\n";
        cout << "Resetting Balance..." << endl;
        //cout << fixed << setprecision(2);
        cout << "Balance = " << balance << endl;
    }
}

double Account::credit(double creditValue)
{
    cout << fixed << setprecision(2);
    cout << "\nValue to add to balance = $" << creditValue << endl;
    balance = balance + creditValue;

    return balance;
}

bool Account::debit(double debitValue)
{
    if (balance < debitValue)
    {
        cout << "\n!!!\tError\t!!!\n";
        cout << "Not enough sufficient funds to withdraw!" << endl;
        return false;
    }
    else
    {
        cout << "\nValue to withdraw from account: $" << debitValue << endl;
        cout << "Processing account...\n";
        cout << "Transaction successful!\n";
        balance = balance - debitValue;
        return true;
    }
}

double Account::getBalance()
{
    return balance;
}

void Account::setBalance(double Balance)
{
    balance = Balance;
    if(Balance > 0)
    {
        cout << "\nBalance = $" /*<< setw(2)*/ << balance << endl;
    }
    else
    {
        balance = 0;
        cout << "\n!!!\tError\t!!!\n";
        cout << "Balance not more than zero!\n";
        cout << "Resetting Balance..." << endl;
        cout << "Balance = " << balance << endl;
    }
}

void Account::printBalance(double getbalance)
{
    cout << fixed << setprecision(2) << endl;
    cout << "---\tCurrent balance in your account = "
         << balance << endl; 
}