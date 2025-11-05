#pragma once
#include <string>
#define MAXCHARS 20
class Person
{
private:
	std::string vorname;
	std::string nachname;
	Person* partner;
public:
	Person();
	Person(std::string vorname , std::string nachname);
	Person(const Person& other);
	Person& operator=(const Person& rhs);
	std::string getName() const;
	std::string getInfo() const;
	void heiraten(Person* const partner);
	void scheiden();
};
