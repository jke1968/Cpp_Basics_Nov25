#include "Konto.h"
#include <iostream>
// : leitet die sog. 
// "member initializer list" ein
Konto::Konto() 
	: Konto(0,0) // Aufruf der 2-arg ctors
{
	std::cout << "default ctor of Konto called" << std::endl;
}

Konto::Konto(int nummer, float saldo)
	: nummer{nummer}, saldo{saldo}
{
	std::cout << "2-arg ctor of Konto called" << std::endl;
}

// In der Implementierungsdatei stehen die
// Definitionen der Member-Funktionen
// Konto:: macht diese Funktion zu einer
// Member-Funktion der Klasse "Konto"
void Konto::einzahlen(float betrag)
{
	saldo += betrag;
}

void Konto::auszahlen(float betrag)
{
	saldo -= betrag;
}

int Konto::getNr() const
{
	return nummer;
}

void Konto::setNr(int nummer)
{
	this->nummer = nummer;
}

float Konto::getSaldo() const
{
	return saldo;
}

Konto::~Konto()
{
	std::cout << "dtor of Konto called" << std::endl;
}
