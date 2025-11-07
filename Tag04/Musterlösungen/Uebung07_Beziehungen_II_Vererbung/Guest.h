#pragma once
#include <string>
class Guest {
private:
	static const int MAXCHARS = 20;
	std::string name;
	std::string address;
public:
	Guest(const std::string& name, const std::string& address);
	Guest();
	const std::string& getName() const;
	const std::string& getAddress() const;
	virtual std::string toString() const; 
	virtual ~Guest();
};