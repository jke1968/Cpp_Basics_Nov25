#pragma once
#include <string>
#include "Konto.h"

constexpr size_t max_konten = 5;

class Kunde
{
private:
	std::string name;
	std::string adresse;
	// Speichere Konto-Pointer, um Polymorphie auszunutzen
	Konto* konten[max_konten];
	size_t kontenZaehler;
public:
	Kunde(std::string name, std::string adresse);
	void addKonto(Konto* k);
	void printKonten() const;
	const std::string& getAdresse() const;
	const std::string& getName() const;
};

