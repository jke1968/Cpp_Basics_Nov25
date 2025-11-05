#include "Kunde.h"
#include <iostream>
Kunde::Kunde(std::string name, std::string adresse)
	: name{name}, adresse{adresse}, kontenZaehler{0}
{
}

void Kunde::addKonto(Konto k)
{
	if (kontenZaehler < max_konten) {
		konten[kontenZaehler] = k;
		kontenZaehler++;
	} else {
		std::cout << "Maximale Kontenanzahl erreicht" << std::endl;
	}
}
void Kunde::printKonten() const
{
	std::cout << "Alle Konten des Kunden " << name << std::endl;
	for (size_t i = 0; i < kontenZaehler; i++)
	{
		std::cout
			<< "Nr: "
			<< konten[i].getNr()
			<< " Saldo: "
			<< konten[i].getSaldo()
			<< std::endl;
	}
}

const std::string& Kunde::getAdresse() const
{
	return adresse;
}

const std::string& Kunde::getName() const
{
	return name;
}


