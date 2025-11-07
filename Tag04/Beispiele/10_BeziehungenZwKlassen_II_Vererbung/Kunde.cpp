#include "Kunde.h"
#include "Girokonto.h"
#include "Sparkonto.h"

#include <iostream>
Kunde::Kunde(std::string name, std::string adresse)
	: name{name}, adresse{adresse}, kontenZaehler{0}
{
}

void Kunde::addKonto(Konto* k)
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
		Konto* k = konten[i];
		std::cout
			<< "Nr: "
			<< k->getNr()
			<< " Saldo: "
			<< k->getSaldo();

		// Vorsicht: ein static cast von Basis- nach Subklasse
		// kann fehlschlagen:
		//std::cout 
		//	<< " Dispo: "
		//	<< static_cast<Girokonto*>(k)->getDispo();

		// Deswegen wird hier ein sog. dynamic_cast verwendet:
		// wenn der dynamic_cast gelingt, kann ein static_cast
		// sicher ausgeführt werden (vgl. "instanceof" in Java
		if (dynamic_cast<Girokonto*>(k) != nullptr) {
			std::cout
				<< " Dispo: "
				<< static_cast<Girokonto*>(k)->getDispo();
		}
		if (dynamic_cast<Sparkonto*>(k) != nullptr) {
			std::cout
				<< " Verfuegungsrahmen: "
				<< static_cast<Sparkonto*>(k)->getVerfRahmen();
		}

		
		std::cout << std::endl;
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


