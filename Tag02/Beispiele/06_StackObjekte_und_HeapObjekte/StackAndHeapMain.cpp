#include <iostream>
#include "A.h"

void demoHeapObjects() {
	std::cout << "enter demoHeapObjects" << std::endl;
	// erzeuge ein Objekt vom Typ A auf dem Heap
	// -> verwende dazu den new Operator
	// -> wie malloc, zusätzlich aber Aufruf des Konstruktors
	A* a1 = new A{};
	A* a2 = new A{};
	A* a3 = new A{};
	std::cout << "exit demoHeapObjects" << std::endl;
	// Heap-Objekte müssen vom Programmierer explizit freigegeben werden
	// -> verwende dazu den delete Operator
	// -> wie free, zusätzlich aber Aufruf des Destruktors
	// -> zu jedem new gehört ein delete
	delete a1;
	delete a2;
	delete a3;
}

void demoStackOjects() {
	std::cout << "enter demoStackObjects" << std::endl;
	// Erzeuge Objekte auf dem Stack:
	A a1{};
	A a2{};
	A a3{};
	std::cout << "exit demoStackObjects" << std::endl;
	// am Ende des scopes werden vom Compiler
	// für jedes lokale Objekt Destruktor-Aufrufe eingefügt
	// -> Stackspeicher heisst deshalb auch: "automatic storage"
}
int main() {
	std::cout << "enter main" << std::endl;
	demoHeapObjects();
	demoStackOjects();
	std::cout << "exit main" << std::endl;
	return 0;
}