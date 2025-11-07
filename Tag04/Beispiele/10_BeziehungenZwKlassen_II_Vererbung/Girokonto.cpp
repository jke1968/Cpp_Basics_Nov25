#include "Girokonto.h"

Girokonto::Girokonto()
	: Konto(), dispo{0}
{
}

Girokonto::Girokonto(int nummer, float saldo, int dispo)
	: Konto(nummer,saldo), dispo{dispo}
{
}

int Girokonto::getDispo() const
{
	return dispo;
}
