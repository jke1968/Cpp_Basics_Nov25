#include "Guest.h"
#pragma warning(disable: 4996)
#include <cstdio>
#include <cstring>

Guest::Guest(const std::string& name, const std::string& address)
	: name{name}, address{address}
{
}
Guest::Guest() : Guest("N.A.","N.A.") {
}
const std::string& Guest::getName() const
{
	return name;
}
const std::string& Guest::getAddress() const
{
	return address;
}

std::string Guest::toString() const
{
	return name + " " + address;
}

Guest::~Guest()
{
	// no destructor needed, because there is no memory allocation
}
