/*
illustrates the use of std::vector and algorithm std::sort
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include "Person.h"


constexpr int max_persons = 3;



void print_persons(std::vector<Person> persons) {
	for (Person p : persons) {
		std::cout << "  " << p.nr << " " << p.name << std::endl;
	}
}

Person* read_person_from_console() {
	size_t number = 0;
	std::string name_ = "";
	char name[20];
	std::cout << "Enter number: ";
	std::cin >> number;
	std::cout << "Enter name: ";
	std::cin >> name;
	Person* p = new Person{};
	p->nr = number;
	p->name = name;
	return p;
}

void read_persons(Person* persons[]) {
	char input = ' ';
	for (int i = 0; i < max_persons; i++) {
		persons[i] = read_person_from_console();
		std::cout << "Continue? (j/n)";
		std::cin >> input;
		if (input == 'n') {
			break;
		}
	}
}

void sort_person_values()
{
	// a pre-initialized array is used here
	std::vector<Person> persons = { {101,"Van Rossum"},{100,"Ritchie"},{102,"Stroustrup"} };
	std::cout << "unsorted" << std::endl;
	print_persons(persons);

	std::sort(persons.begin(), persons.end(), [](const Person& p1, const Person& p2)
		{
			return p1.nr < p2.nr;
		}
	);
	std::cout << "sorted by number" << std::endl;
	print_persons(persons);

	std::sort(persons.begin(), persons.end(), [](const Person& p1, const Person& p2)
		{
			return p1.name < p2.name;
		}
	);
	std::cout << "sorted by name" << std::endl;
	print_persons(persons);
}

int main() {
	sort_person_values();
	return 0;
}

