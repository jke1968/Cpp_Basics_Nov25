/*
illustrates the use of function pointers by using qsort
*/
#include <iostream>
#include "Person.h"
#include <stdlib.h>

constexpr int max_persons = 3;

int compare_person_ptrs_by_nr(const void* a, const void* b)
{
	const Person** arg1 = (const Person**)a;
	const Person** arg2 = (const Person**)b;

	if ((*arg1)->nr < (*arg2)->nr) return -1;
	if ((*arg1)->nr > (*arg2)->nr) return 1;

	return 0;
}
int compare_person_ptrs_by_name(const void* a, const void* b)
{
	const Person** arg1 = (const Person**)a;
	const Person** arg2 = (const Person**)b;

	if ((*arg1)->name < (*arg2)->name) return -1;
	if ((*arg1)->name > (*arg2)->name) return 1;

	return 0;
}
int compare_person_values_by_nr(const void* a, const void* b)
{
	const Person* arg1 = (const Person*)a;
	const Person* arg2 = (const Person*)b;

	if (arg1->nr < arg2->nr) return -1;
	if (arg1->nr > arg2->nr) return 1;

	return 0;
}

int compare_person_values_by_name(const void* a, const void* b)
{
	const Person* arg1 = (const Person*)a;
	const Person* arg2 = (const Person*)b;

	if (arg1->name < arg2->name) return -1;
	if (arg1->name > arg2->name) return 1;

	return 0;
}

void print_person_ptrs(Person* persons[]) {
	for (int i = 0; i < max_persons; i++) {
		std::cout << "  " << persons[i]->nr << " " << persons[i]->name << std::endl;
	}
}
void print_person_values(Person persons[]) {
	for (int i = 0; i < max_persons; i++) {
		std::cout << "  " << persons[i].nr << " " << persons[i].name << std::endl;
	}
}

Person* read_person_from_console() {
	size_t number = 0;
	std::string name = "";
	std::cout << "Enter number: ";
	std::cin >> number;
	std::cout << "Enter name: ";
	std::cin >> name;
	Person* p = new Person{ number,name };
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
void initPersons(Person* persons[]) {
	persons[0] = new Person{ 101,"Ritchie" };
	persons[1] = new Person{ 102,"Stroustrup" };
	persons[2] = new Person{ 100,"van Rossum" };
}

void sort_person_ptrs() 
{
	Person* persons[max_persons];

	read_persons(persons);

	std::cout << "unsorted" << std::endl;
	print_person_ptrs(persons);

	std::cout << "sorted by number" << std::endl;
	qsort(persons, max_persons, sizeof(Person*), compare_person_ptrs_by_nr);
	print_person_ptrs(persons);

	std::cout << "sorted by name" << std::endl;
	qsort(persons, max_persons, sizeof(Person*), compare_person_ptrs_by_name);
	print_person_ptrs(persons);

}

void sort_person_values()
{
	// a pre-initialized array is used here
	Person persons[max_persons] = { {101,"Van Rossum"},{100,"Ritchie"},{102,"Stroustrup"} };

	std::cout << "unsorted" << std::endl;
	print_person_values(persons);

	std::cout << "sorted by number" << std::endl;
	qsort(persons, max_persons, sizeof(Person), compare_person_values_by_nr);
	print_person_values(persons);

	std::cout << "sorted by name" << std::endl;
	qsort(persons, max_persons, sizeof(Person), compare_person_values_by_name);
	print_person_values(persons);

}

int main() {
	sort_person_ptrs();
	return 0;
}

