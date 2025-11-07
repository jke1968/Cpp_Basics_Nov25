#pragma once
#include "Konto.h"
// Girokonto ist Subklasse von Konto
class Girokonto : public Konto
{
private:
	int dispo;
public:
	Girokonto();
	Girokonto(int nummer, float saldo, int dispo);
	int getDispo() const;
};

