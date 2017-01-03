#ifndef PROFESSOR_H
#define PROFESSOR_H

class Professor
{
public:
	Professor();
	Professor(std::string, std::string, std::string, std::string, std::string);
	~Professor();
	void printProf();

private:
	std::string firstName;
	std::string lastName;
	std::string roomNum;
	std::string emailInfo;
	std::string phoneNum;
};

#endif /* */