#pragma once
#include "Base.h"
class Sub : public Base
{
public:
	// überschreibe die virtual member function "f()" aus der Basisklasse:
	// override verhindert die Modifikation der Signatur der überschreibenden 
	// Funktion
	void f() override;
};

