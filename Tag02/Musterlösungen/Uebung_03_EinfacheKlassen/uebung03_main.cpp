/*
illustrates the usage of a simple class
to create both stack and heap objects
*/
#include <iostream>
#include <iomanip>
#include "Date.h"

void createStackObjects() {
	Date dates[] = { { "05-11-2025" },{ "04-11-2025" }, { "06-11-2025" } };
	Date oldest = dates[0];
	for (int i = 1; i < 3; i++) {
		if (dates[i].isBefore(oldest)) {
			oldest = dates[i];
		}
	}
	std::cout << "oldest date "
		<< oldest.getDay() << " "
		<< oldest.getMonth() << " "
		<< oldest.getYear()
		<< std::endl;
}
void createHeapObjects() {
	Date* dates[3] = {
		{new Date{"01-01-2025"}},
		{new Date{"01-01-2024"}},
		{new Date{"01-01-2023"}}
	};
	Date* oldest = dates[0];
	for (int i = 1; i < 3; i++) {
		if (dates[i]->isBefore(*oldest)) {
			oldest = dates[i];
		}
	}
	std::cout << "oldest date "
		// use std::setw for 2 char columns
		// std::setfill to fill with leading 0s
		<< std::setw(2)      
		<< std::setfill('0')
		<< oldest->getDay() << " "
		<< std::setw(2)
		<< std::setfill('0')
		<< oldest->getMonth() << " "
		<< std::setw(4)
		<< std::setfill('0')
		<< oldest->getYear()
		<< std::endl;
	// free heao memory
	for (int i = 0; i < 3; i++) {
		delete dates[i];
	}


}

int main() {
	int number = 0;
	while (true) {
		std::cout << "enter number: ";
		std::cin >> number;
		std::cout << "you entered: " << number << std::endl;
	}
	createStackObjects();
	createHeapObjects();
	return 0;

}