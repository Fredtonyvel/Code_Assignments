#include <string>
#include <iostream>

#include "Professor.h"
#include "list.h"

using namespace std;

int main()
{
	Professor f("Freddy", "Velez", "5.15NB", "vfredanthony@yahoo.com", "347-813-6946");
	//f.printProf();
	Professor p("Angelica", "Velez", "6.63NB", "a_vele@hotmail.com", "347-239-1576");
	Professor a("Emely", "Velez", "7.63NB", "emely_vele@gmail.com", "347-239-4675");
	//cin >> p;
	//cout << p;

	list ll;
	//ll.addToHead(f);
	//ll.addToHead(p);
	ll.addToTail(f);
	ll.addToTail(p);
	//ll.addNode(f,1);
	//ll.addNode(p,2);
	//ll.addNode(a,3);
	ll.print();

	return 0;
}