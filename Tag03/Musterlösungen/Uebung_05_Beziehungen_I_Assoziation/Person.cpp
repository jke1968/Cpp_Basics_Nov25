#include "Person.h"
using namespace std;

Person::Person() : Person("N.A.","N.A.") {
}
Person::Person(std::string vorname, std::string nachname) :
	partner(NULL), vorname{vorname}, nachname{nachname}
{
}
Person::Person(const Person& other)
{
	vorname = other.vorname;
	nachname = other.nachname;
	if (other.partner != nullptr) {
		Person* partner = new Person(other.vorname, other.nachname);
		this->partner = partner;
	} else {
		this->partner = nullptr;
	}
}
Person& Person::operator=(const Person& rhs)
{
	if (this != &rhs) {
		vorname = rhs.vorname;
		nachname = rhs.nachname;
		
	}
	return *this;
}
std::string  Person::getName() const
{
	return vorname + " " + nachname;
}
std::string Person::getInfo() const
{
	std::string info = getName();
	if (this->partner == NULL) {
		info += " ledig";
	} else {
		info += " verheiratet mit ";
		info += this->partner->getName();
	}
	return info;
}
void Person::heiraten(Person* const partner) {
	if (partner != NULL && partner != this ) {
		if (this->partner == NULL && partner->partner == NULL ) {
			this->partner = partner;
			partner->partner = this;
		}
	}
}
void Person::scheiden() {
	if (this->partner != NULL) {
		this->partner->partner = NULL;
		this->partner = NULL;
	}
}

