#pragma once
#include <stdint.h>
class Date
{
private:
	uint16_t _day;
	uint16_t _month;
	uint16_t _year;
public:
	Date();
	Date(const char* s);
	uint16_t getDay() const;
	void setDay(uint16_t day);
	uint16_t getMonth() const;
	void setMonth(uint16_t day);
	uint16_t getYear() const;
	void setYear(uint16_t day);

	bool isBefore(const Date& date);
	bool isEqual(const Date& date);

	// or also 
	uint16_t& day();
	const uint16_t& day() const;
	uint16_t& month();
	const uint16_t& month() const;
	uint16_t& year();
	const uint16_t& year() const;

};

