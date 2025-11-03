// iostream ist ein Headerfile 
// aus der C++ Standardbibliothek
#include <iostream>
// Hier wird eine Kopie der Variablen
// "number" aus der Funktion "main" übergeben
void incrementNumber(int number) {
	number++;
	std::cout << "in function: " << number << std::endl;
}
bool isNumberEven(int number) {
	if (number % 2 == 0) {
		return true;
	} else {
		return false;
	}
}
int main() {
	int number = 0;
	do {
		// std ist ein sogenannter "namespace" 
		// -> ein Präfix für einen Variablennamen
		std::cout << "Enter number (quit with 0): " << std::endl;
		std::cin >> number;
		std::cout << "You entered: " << number << std::endl;
		incrementNumber(number);
		std::cout << "after function: " << number << std::endl;
		if (isNumberEven(number)) {
			std::cout << number << " is even" << std::endl;
		} else {
			std::cout << number << " is odd" << std::endl;
		}
	} while (number != 0);
	return 0;
}