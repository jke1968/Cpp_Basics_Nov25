#include "PrivatePartner.h"
#include <cstring>
#pragma warning (disable: 4996)
PrivatePartner::PrivatePartner() : PrivatePartner{"N.A.","N.A.","N.A."} {
}
PrivatePartner::PrivatePartner(const std::string& name, const std::string& address, const std::string& agency)
	: Guest{ name,address }, agency{agency}
{
}

const std::string& PrivatePartner::getAgency() const
{
	return agency;
}

std::string PrivatePartner::toString() const
{
	return Guest::toString() + " Travel Agency: " + agency;
}

