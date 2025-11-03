#include <iostream>

// diese Funktion soll die Original-Variable in main ändern
// #1 : übergebe einen "pointer to int"
// * bedeutet hier: der Typ der Variablen 
// number ist "pointer to int"
void incrementNumber(int* number) {
	// #2 derefenziere den Pointer
	// * ist hier der "Dereferenz-Operator"
	(*number)++;
	std::cout << "in incrementNumber: " << *number << std::endl;
}
int globalNumber = 17;
// number ist hier vom Typ "int-Referenz"
void incrementNumberCppStyle(int& number) {
	// einer C++-Referenz kann keine andere Adresse zugewiesen werden:
	// number = &globalNumber;
	// eine C++-Referenz muss nicht derefenziert werden
	number++;
	std::cout << "in incrementNumberCppStyle: " << number << std::endl;
}

int main() {
	int number = 0;
	std::cout << "Enter number: ";
	std::cin >> number;
	// #3 übergebe die Adresse der Variablen in main
	// & ist der "Adress-Operator"
	incrementNumber(&number);
	std::cout << "in main: " << number << std::endl;
	// wenn der Parameter einer Funktion eine Referenz ist,
	// dann muss kein Adress-Operator beim Aufruf verwendet werden
	incrementNumberCppStyle(number);
	std::cout << "in main: " << number << std::endl;
	return 0;
}