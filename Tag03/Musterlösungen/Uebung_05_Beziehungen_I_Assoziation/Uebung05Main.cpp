#include <iostream>
#include "Person.h"

int main()
{
	std::cout << "enter main" << std::endl;
	Person p1("Paul", "Breitner");
	Person p2("Nadine", "Angerer");

	std::cout << p1.getInfo() << std::endl;
	std::cout << p2.getInfo() << std::endl;

	p1.heiraten(&p2);
	
	std::cout << p1.getInfo() << std::endl;
	std::cout << p2.getInfo() << std::endl;

	p1.scheiden();

	std::cout << p1.getInfo() << std::endl;
	std::cout << p2.getInfo() << std::endl;

	std::cout << "exit main" << std::endl;
	return 0;
}