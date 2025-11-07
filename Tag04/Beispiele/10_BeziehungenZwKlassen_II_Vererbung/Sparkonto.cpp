#include "Sparkonto.h"

Sparkonto::Sparkonto()
	: Konto(), verfRahmen{ 0 } // rufe den Konstruktor der Basisklasse Konto
{
}

Sparkonto::Sparkonto(int nummer, float saldo, int verfRahmen)
	: Konto(nummer, saldo), verfRahmen{verfRahmen}
{
}

int Sparkonto::getVerfRahmen() const
{
	return verfRahmen;
}
