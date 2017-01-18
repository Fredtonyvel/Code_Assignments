#include <string>
#include <iostream>

#include "Professor.h"
#include "list.h"

using namespace std;

int main()
{
	Professor prof("Freddy", "Velez", "5.15NB", "vfredanthony@yahoo.com", "347-813-6946");
	//prof.printProf();

	list ll;
	ll.addToHead(prof);
	ll.print();

	return 0;
}