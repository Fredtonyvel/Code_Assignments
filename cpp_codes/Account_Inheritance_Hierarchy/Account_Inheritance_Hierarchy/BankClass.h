#ifndef	BANK_CLASS_H
#define BANK_CLASS_H

#include "Account.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include <iostream>
#include <fstream>
#include <string>
#include <regex>

using namespace std;

class Bank : public Account, public SavingsAccount, public CheckingAccount
{
private:

public:
	void loadBalance();
    void viewHistory();
};

#endif //BANK_CLASS_H