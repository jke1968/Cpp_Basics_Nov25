#pragma once
#include "Konto.h"
// Sparkonto ist Subklasse von Konto
class Sparkonto : public Konto
{
private:
	int verfRahmen;
public:
	Sparkonto();
	Sparkonto(int nummer, float saldo, int verfRahmen);
	int getVerfRahmen() const;
};

