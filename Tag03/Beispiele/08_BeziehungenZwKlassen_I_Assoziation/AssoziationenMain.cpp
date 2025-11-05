#include <iostream>
#include "Kunde.h"
#include "Konto.h"

int main() {
	std::cout << "enter main" << std::endl;
	Kunde k{"Lara","Stadtmitte"};
	k.addKonto(Konto{ 100,99.99f });
	k.addKonto(Konto{ 101,0.00f });
	k.printKonten();
	std::cout << "exit main" << std::endl;
	return 0;
}