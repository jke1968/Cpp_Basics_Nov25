#include "Guest.h"
#include <string>
class Hotel {
private:
	static const int MAXCHARS = 20;
	std::string name;
	std::string address;
	static const int MAXROOMS = 5;
	Guest* rooms[MAXROOMS];
public:
	Hotel(const std::string& name, const std::string& address);
	int checkIn(Guest* guest);
	void checkOut(int roomNr);
	void printStatus() const;
	const std::string& getName() const;
	const std::string& getAddress() const;
	virtual ~Hotel();
};
