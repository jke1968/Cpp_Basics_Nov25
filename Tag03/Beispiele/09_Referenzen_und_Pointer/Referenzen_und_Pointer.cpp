#include <iostream>

int add(int i1, int i2) {
	return i1 + i2;
}

int main(int argc, char** argv) {
	// References & vs. Pointer *
	// ===========================
	// Gemeinsamkeit: in beiden Fällen handelt es sich um Speicheradressen
	
	// i ist ein "value type", d.h. in dieser Variablen
	// ist ein Wert gespeichert und keine Adresse
	int i = 0;
	int j = 1;
	std::cout << "Adresse von i: " << &i << " Wert von i: " << i << std::endl;
	// In C und C++ möglich: definiere einen Pointer auf die Variable i
	int* pointer_to_int = &i;
	// Nur in C++ möglich: definiere eine Referenz auf i
	int& reference_to_int = i;
	// Unterschied #1 keine Pointer-Syntax nötig für Referenzen
	std::cout 
		<< "pointer_to_int: "
		<< *pointer_to_int
		<< " reference_to_int: "
		<< reference_to_int
		<< std::endl;
	// Unterschied #2 Referenzen können nur auf das Objekt
	// zeigen, mit dem sie initialisiert wurden
	pointer_to_int = &j; // geht mit pointern
	// reference_to_int = &j; // geht nicht mit Referenzen, denn int != int*
	// Unterschied #3 Referenzen können nicht NULL sein
	pointer_to_int = nullptr; // geht mit pointern
	int* other_pointer_to_int;

	// reference_to_int = nullptr; // geht nicht mit Referenzen
	// int& other_reference; // geht nicht mit Referenzen
	// int& other_reference = nullptr;

	// Unterschied #4 : pointer können auf Arrays zeigen
	int numbers[3] = { 1,2,3 };
	int* pointer_to_array = numbers; // geht mit Pointern
	// int& reference_to_array = numbers; // geht nicht mit Referenzen
	// int& reference_to_array = &numbers;

	// Unterschied #5 pointer können inkrementiert und dekrementiert werden
	pointer_to_array++;
	std::cout
		<< "pointer_to_array points to the value: "
		<< *pointer_to_array
		<< std::endl;
	pointer_to_array--;
	std::cout
		<< "pointer_to_array points to the value: "
		<< *pointer_to_array
		<< std::endl;

	// Unterschied #6 pointer-Variablen haben eigene Adressen,
	//                Referenzen haben dieselbe Adresse wie das referenzierte
	//                Objekt
	pointer_to_int = &i;
	reference_to_int = i;
	std::cout
		<< "address of i:             "
		<< &i
		<< std::endl;
	std::cout
		<< "address of   pointer_to_i "
		<< &pointer_to_int
		<< std::endl;
	std::cout
		<< "address of reference_to_i "
		<< &reference_to_int // ist dieselbe Adresse wie &i
		<< std::endl;
	// Unterschied #7 Pointer können auf Pointer zeigen, Referenzen nicht
	int** pointer_to_pointer_to_int = &pointer_to_int;
	// int&& reference_to_reference_to_int = &reference_to_int; // geht nicht

	// Unterschied #8 : Pointer können in Arrays gespeichert werden, 
	//                  Referenzen nicht
	int* array_of_int_pointers[1] = { pointer_to_int };
	// int& array_of_int_references[1] = { reference_to_int }; // geht nicht

	// Unterschied #9: pointer können auf Funktionen zeugen, Referenzen nicht
	// Definiere einen Pointer auf eine Funktion mit der Signatur int (int,int)
	int(*pointer_to_function)(int, int) = &add;
	// verwende den Pointer, um die Funktion aufzurufen:
	
	std::cout << "1 + 1 = " << pointer_to_function(1, 1) << std::endl;

	return 0;
}