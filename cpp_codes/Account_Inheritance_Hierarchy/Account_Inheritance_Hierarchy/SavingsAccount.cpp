#include "SavingsAccount.h"
#include <iostream>
#include <fstream>
#include <string>
#include <regex>

using namespace std;

SavingsAccount::SavingsAccount() : Account()
{
	interestRate = 0;
}

SavingsAccount::SavingsAccount(double Balance, double rate): Account(Balance)
{
	balance = Balance;
    interestRate = rate;
    cout << "Rate = " << interestRate << "%" << endl;
}

double SavingsAccount::calculateInterest()
{
	interest = balance*(interestRate/100);
	return interest;
}

double SavingsAccount::setInterest(double int_rate)
{
	interestRate = int_rate;
	return interestRate;
}

double SavingsAccount::getInterest()
{
	return interestRate;
}

void SavingsAccount::printRate()
{
	cout << "---\tCurrent Interest Rate = " 
		 << getInterest() << "%\t---" << endl;
}

void SavingsAccount::loadBalance()
{
	ifstream file("User.txt");
	int count = 0, value = 0;
	double fbalance = 0;
	string line, result;

	if (file.is_open())
	{
		try
        {
            regex re("Balance = (.*)"); //regex to search everything after the '=' sign
            smatch match;
            while(getline(file, line))
            {
                //cout << line << endl;
                if (regex_search(line, match, re))  //take each line and search for pattern match
                {
                    result = match.str(1);  //only obtain specific part not the whole string
                    fbalance = stof(result);   //convert string to float
                    value++;
                }

                //Counting number of characters in file
                for (int i = 0; i < line.length(); i++)
                {
                    count++;
                }
            }
        }
        catch(regex_error& e) {}
        cout << fixed << setprecision(2);
        cout << "\nfbalance = $" << fbalance << endl;	
	}

	double rate;
    cout << "\nEnter interest for the account:";
    cin >> rate; 

   
    setBalance(fbalance);
    setInterest(rate);

	file.close();
}

void SavingsAccount::viewHistory()
{
	ifstream file("User.txt");
	string line;

	if (file.is_open())
	{
		while(getline(file, line))
			cout << line << endl;
	}

	file.close();
}