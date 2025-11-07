#pragma once
#include "Guest.h"
#include <string>
class PrivatePartner : public Guest
{
private:
	std::string agency;
public:
	PrivatePartner();
	PrivatePartner(const std::string& name, const std::string& address, const std::string& agency);
	const std::string& getAgency() const;
	virtual std::string toString() const override;

};

