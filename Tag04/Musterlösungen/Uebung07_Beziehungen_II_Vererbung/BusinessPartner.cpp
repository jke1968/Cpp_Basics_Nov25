#include "BusinessPartner.h"

BusinessPartner::BusinessPartner() : BusinessPartner{"N.A.","N.A.",0} {
}

BusinessPartner::BusinessPartner(const std::string& name, const std::string& address, int discount)
	: Guest{ name,address }, discount{ discount }
{
}

std::string BusinessPartner::toString() const
{
	return Guest::toString() + " Discount: " + std::to_string(discount);
}


int BusinessPartner::getDiscount() const
{
	return discount;
}
