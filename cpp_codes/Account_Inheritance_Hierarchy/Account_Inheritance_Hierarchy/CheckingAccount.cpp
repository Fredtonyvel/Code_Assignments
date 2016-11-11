#include "CheckingAccount.h"
#include <iostream>

using namespace std;

CheckingAccount::CheckingAccount(double Balance, double Fee) : Account(Balance)
{
	fee = Fee;
}

bool CheckingAccount::chargeFee()
{
	if (fee < balance)
	{
		balance = balance - fee;
		return true;
	}
	else
		return false;
}

double CheckingAccount::setFee(double newFee)
{
	fee = newFee;
	return fee;
}

double CheckingAccount::getFee()
{
	return fee;
}

void CheckingAccount::printFee()
{
	cout << "---\tCurrent Fee = $" 
		 << getFee() << "\t---" << endl;
}