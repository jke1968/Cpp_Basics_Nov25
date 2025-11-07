#include <iostream>
#include "Base.h"
#include "Sub.h"

// 2-fach überladende Funktion add
// überladen heisst: gleicher Name, aber unterschiedliche Parameterliste
int add(int i1, int i2) {
	return i1 + i2;
}
int add(int i1, int i2, int i3) {
	return i1 + i2 + i3;
}
int main() {
	Base* b1 = new Base();
	Base* b2 = new Sub();
	// *** Überschreiben ***
	// hier generiert der C++ Compiler Maschinencode,
	// der zur Laufzeit eine Fallunterscheidung beinhaltet, die vom
	// Typ des konreten Objekts b1, bzw. b2 Gebrauch macht
	b1->f();
	b2->f();
	// Offenbar hat die Member-Funktion f verschiedene Implementierungen 
	// in verschiedenen Klassen: sie ist eine sog. polymorphe Funktion

	// *** Überladen ***
	// rufe 1. Überladung von add
	std::cout << add(1, 2) << std::endl;
	// rufe 2. Überladung von add
	std::cout << add(1, 2, 3) << std::endl;
	return 0;
}