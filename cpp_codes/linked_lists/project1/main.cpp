#include <string>
#include <iostream>

#include "Professor.h"
#include "list.h"

using namespace std;

int main()
{
	Professor obj("Freddy", "Velez", "5.15NB", "vfredanthony@yahoo.com", "347-813-6946");
	//obj.printProf();

	list obj2;
	obj2.addToHead(obj);
	obj2.print();

	return 0;
}