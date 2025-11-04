#include <iostream>
#include "Konto.h"

void printKontoInfo(const Konto& konto) {
	std::cout << "Nr: " << konto.getNr() << " Saldo: " << konto.getSaldo() << std::endl;
}

int main() {
	std::cout << "enter main" << std::endl;
	// Definiere eine Variable vom Typ Konto
	// hier wird, im Gegensatz zu Java,
	// ein Objekt der Klasse Konto erzeugt,
	// ohne den Aufruf des new Operators
	Konto k1; // Aufruf des Default-Konstruktors
	Konto k2{}; // auch Aufruf des Default-Konstruktors
	Konto k3{ 100,9999.99f }; // Aufruf des 2-arg-Konstruktors
	k1.einzahlen(100.99f);
	k2.einzahlen(5.55f);
	printKontoInfo(k1);
	printKontoInfo(k2);
	printKontoInfo(k3);
	std::cout << "exit main" << std::endl;
	return 0;
}