#pragma warning(disable: 4996)
#include "Guest.h"
#include "Hotel.h"
#include "BusinessPartner.h"
#include "PrivatePartner.h"
#include <iostream>
#include "FullyBookedException.h"
/*
constructs a hotel with emtpy rooms and given name and address
*/
Hotel::Hotel(const std::string& name, const std::string& address) 
	: name{name}, address{address}
{
	for (int i = 0; i < MAXROOMS; i++) {
		rooms[i] = nullptr;
	}
}
/*
tries to check-in guest in next free room
returns room number if successful
*/
int Hotel::checkIn(Guest* guest) {
	bool checkedIn = false;
	int roomNr = 0;
	for (; roomNr < MAXROOMS; roomNr++) {
		if (rooms[roomNr] == nullptr) {
			rooms[roomNr] = guest;
			checkedIn = true;
			break;
		}
	}
	if (!checkedIn) {
		throw FullyBookedException{ "Could not check-in guest" + guest->getName() };
	} else {
		return roomNr;
	}
}
/*
tries to check-out guest from given room
*/
void Hotel::checkOut(int roomNr) {
	if (rooms[roomNr] != nullptr) {
		std::cout
			<< "Checked-out guest "
			<< rooms[roomNr]->getName()
			<< " of room no "
			<< roomNr
			<< std::endl;
		rooms[roomNr] = nullptr;
	} else {
		std::cout
			<< "Could not check-out guest of room no "
			<< roomNr
			<< " room is empty"
			<< std::endl;
	}
}
/*
prints list of all rooms
*/
void Hotel::printStatus() const {
	std::cout << "Rooms and guests in Hotel " << name << std::endl;
	std::cout << "=====================================" << std::endl;
	for (int i = 0; i < MAXROOMS; i++) {
		Guest* g = rooms[i];
		std::cout << "Room no: " << i << "  ";
		if (g != nullptr) {
			std::cout << g->toString();
		} else {
			std::cout << "** Available **";
		}
		std::cout << std::endl;
	}
}
const std::string& Hotel::getName() const {
	return name;
}
const std::string& Hotel::getAddress() const {
	return address;
}
Hotel::~Hotel() {
	// no allocated memory to delete
}