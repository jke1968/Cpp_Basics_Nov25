#pragma warning(disable: 4996)
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include "Hotel.h"
#include "Guest.h"
#include "BusinessPartner.h"
#include "PrivatePartner.h"
#include "FullyBookedException.h"
using namespace std;

Hotel hotel("Holiday Inn", "Weilimdorf");

void checkInGast() {
	const int MAXCHARS = 20;
	std::string name;
	std::string address;
	std::string agency;
	int discount = 0;
	Guest* guest = nullptr;
	int choice = 1;

	std::cout << "Name: ";
	std::cin >> name;
	std::cout << "Address: ";
	std::cin >> address;

	std::cout << "BusinessPartner(1) / PrivatePartner(2): " << std::endl;
	std::cin >> choice;
	switch (choice) {
	case 1:
		printf("Discount: ");
		std::cin >> discount;
		guest = new BusinessPartner(name, address, discount);
		break;
	case 2:
		printf("Agency: ");
		std::cin >> agency;
		guest = new PrivatePartner(name, address, agency);
		break;
	default:
		printf("Unknown guest type\n");
		break;
	}
	try {
		int roomNo = hotel.checkIn(guest);
		std::cout << "Checked in " << guest->getName() << " into room no " << roomNo;
	} catch (FullyBookedException ex) {
		std::cout << ex.what() << std::endl;
	}
}

void checkOutGast() {
	int roomNr = 0;
	std::cout << "RoomNr: ";
	cin >> roomNr;
	hotel.checkOut(roomNr);
}
void testCheckIn() {
	hotel.checkIn(new Guest{ "Ritchie","Murray Hill" });
	hotel.checkIn(new PrivatePartner{ "Stroustrup","New York City","TUI"});
	hotel.checkIn(new BusinessPartner{ "Gosling","Los Angeles",15 });
}
int main() 
{
	testCheckIn();
	int nr = 0;
	do {
		printf("Was wollen Sie tun ?\n");
		printf("1 - Hotelstatus ausgeben \n");
		printf("2 - Gast in Zimmer einchecken\n");
		printf("3 - Gast aus Zimmer auschecken\n");
		printf("4 - Programm beenden\n");
		scanf("%d", &nr);
		switch (nr) {
		case 1:
			hotel.printStatus();
			break;
		case 2:
			checkInGast();
			break;
		case 3:
			checkOutGast();
			break;
		case 4:
			break;
		default:
			std::cout << "Falsche Eingabe" << std::endl;
			break;
		}
	} while (nr != 4);

	return 0;
}
