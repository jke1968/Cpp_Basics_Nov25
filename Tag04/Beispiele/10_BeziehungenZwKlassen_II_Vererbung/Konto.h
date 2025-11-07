#pragma once
class Konto 
{
private:
	int nummer;
	float saldo;
public:
	Konto();
	Konto(int nummer, float saldo);
	void einzahlen(float betrag);
	void auszahlen(float betrag);
	int getNr() const;
	void setNr(int nummer);
	float getSaldo() const;

	virtual ~Konto();
};

