#include "Konto.h"
#include "Kunde.h"
#include "Girokonto.h"
#include "Sparkonto.h"
#include <iostream>

void createKontoObjects() {
	Kunde k1{ "Ritchie","New York" };
	Konto* konto = new Konto{ 100,5.55f };
	Girokonto* gk = new Girokonto{ 101,0.00f,5000 };
	Sparkonto* sk = new Sparkonto{ 102,9.99f,2500 };
	k1.addKonto(konto);
	k1.addKonto(gk);
	k1.addKonto(sk);
	k1.printKonten();
	delete konto;
	delete gk;
	delete sk;
}

int main() {
	std::cout << "enter main" << std::endl;
	createKontoObjects();
	std::cout << "exit main" << std::endl;
	return 0;
}
