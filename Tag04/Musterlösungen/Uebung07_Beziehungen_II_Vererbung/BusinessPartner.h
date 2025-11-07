#pragma once
#include "Guest.h"
#include <string>
class BusinessPartner : public Guest
{
private:
	int discount;
public:
	BusinessPartner();
	BusinessPartner(const std::string& name, const std::string& address, int discount);
	int getDiscount() const;
	virtual std::string toString() const override;
};

