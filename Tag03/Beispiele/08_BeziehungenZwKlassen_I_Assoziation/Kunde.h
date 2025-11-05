#pragma once
#include <string>
#include "Konto.h"

// Konstante in C++
constexpr size_t max_konten = 5;

class Kunde
{
private:
	std::string name;
	std::string adresse;
	// 0..5 Assoziation zur Klasse Konto:
	Konto konten[max_konten];
	size_t kontenZaehler;
public:
	Kunde(std::string name, std::string adresse);
	void addKonto(Konto k);
	void printKonten() const;
	const std::string& getAdresse() const;
	const std::string& getName() const;
	// keine Destruktor (und damit auch keine "rule-of-three" nötig,
	// denn diese Klasse alloziert keinen Speicher
	// (bzw. nur über die STL Klasse std::string)
};

