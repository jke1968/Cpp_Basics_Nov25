#pragma once
/*
"the rule of three" (C++) -> nach Scott Meyers ("Effective C++")

Wenn eine Klasse Ressourcen alloziert, dann  braucht sie:

1. einen Destruktor
2. einen benutzerdefinierten Copy-Konstruktor
3. einen benutzerdefinierten Assignment-Operator

um korrekt zu funktionieren.

*/
class Container
{
private:
	// die Anzahl der Elemente im gekapselten Array
	size_t size;
	// das gekapselte dynamische Array
	int* elements;
public:
	Container(size_t size);
	// weil diese Klasse Speicher alloziert,
	// braucht sie einen user-defined Copy-Constructor
	// anstelle des Compiler-definierten Copy-Constructors
	Container(const Container& original);
	// aus demselben Grund braucht die Klasse auch einen 
	// user-defined assignment operator
	Container& operator=(const Container& rhs); // rhs = "right hand side" 
	void printElements() const;
	void modify(int i);
	~Container();
};

