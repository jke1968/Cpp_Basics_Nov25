// verhindert das mehrfache
// Einfügen dieser Datei
#pragma once
// Eine Klasse definiert einen neuen Datentyp
// Klassen in C++ = 
// C-Structs + private/protected/public 
// + Member-Funktionen
// (Zusatz: C++structs verhalten sich wie Klassen
// nur sind alle member per default public)
class Konto 
{
// Die privaten Member-Variablen
// (-> Attribute)
private:
	int nummer;
	float saldo;
// Die public Member-Funktionen
public:
	// 2-fach überladener Konstruktor
	Konto();
	Konto(int nummer, float saldo);
	// in einer Header-Datei stehen
	// nur die Deklarationen der Member-Funktionen
	void einzahlen(float betrag);
	void auszahlen(float betrag);
	// getter/setter
	// const member-Funktionen
	// können keine member-Variablen
	// modifizieren
	int getNr() const;
	void setNr(int nummer);
	// saldo ist read-only
	float getSaldo() const;

	// Destruktor der Klasse "Konto":
	~Konto();
};

