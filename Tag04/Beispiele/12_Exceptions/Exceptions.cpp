#include <iostream>
#include <exception>
#include "nenner_null_exception.h"
int teile(int zaehler, int nenner) {
	int ergebnis = 0;
	if (nenner != 0) {
		ergebnis = zaehler / nenner;
	} else {
		// hier wird ein exception Objekt erzeugt und 
		// anstelle des Rückgabewerts an den Aufrufer zurückgegeben
		throw nenner_null_exception{ "Teilen durch 0 nicht moeglich" };
	}
	return ergebnis;
}

void call_teile(int zaehler, int nenner) {
	std::cout << "enter call_teile" << std::endl;
	int ergebnis = 0;
	try {
		ergebnis = teile(4, 0);
		std::cout << "ergebnis= " << ergebnis << std::endl;
	}
	// wird die exception nicht per try..catch behandelt,
	// dann wird sie an die rufende Funktion weitergereicht
	// findet sie nirgendwo auf dem call-stack einen try..catch Block
	// dann wird das Programm abgebrochen ("abort has been called")
	catch (const nenner_null_exception ex) {
		std::cout << "Nenner null exception caught: " << ex.what() << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << "Exception caught: " << ex.what() << std::endl;
	}
	std::cout << "exit call_teile" << std::endl;
}

int main() {
	std::cout << "enter main" << std::endl;
	call_teile(4, 2);
	std::cout << "exit main" << std::endl;
	return 0;
}