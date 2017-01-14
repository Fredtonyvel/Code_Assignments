#ifndef PROFESSOR_H
#define PROFESSOR_H

class Professor
{
public:
	Professor();
	Professor(std::string, std::string, std::string, std::string, std::string);
	~Professor();

	std::string getFirstName();
	std::string getLastName();
	std::string getRoomNum();
	std::string getEmail();
	std::string getPhone();
	void printProf();

private:
	std::string firstName;
	std::string lastName;
	std::string room;
	std::string email;
	std::string phone;
};

#endif /* */