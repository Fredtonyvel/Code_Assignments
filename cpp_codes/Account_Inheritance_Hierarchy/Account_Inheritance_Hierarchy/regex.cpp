#include <iostream>
#include <iomanip>
#include <string>
#include <regex>

using namespace std;

int main()
{
	std::string subject("Balance = 1000.00");
	std::string result;
	float final;
	try 
	{
		std::regex re("Balance = (.*)");
	  	std::smatch match;
	  	if (std::regex_search(subject, match, re) /*&& match.size() > 1*/) 
	  	{
	  		result = match.str(1);
	    	final = stoi(result);
	    	final = final + 200.25;
	    	cout << fixed << setprecision(2) << "result = " << final << endl;
	  	} 
	  	else 
	  	{
	    	result = std::string("");
	  	} 
	} 
	catch (std::regex_error& e) 
	{
	  // Syntax error in the regular expression
	}

	return 0;
}