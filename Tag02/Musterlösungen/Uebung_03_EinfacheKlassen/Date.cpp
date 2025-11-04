#include "Date.h"
#include <iostream>

Date::Date() 
	: _day{0}, _month{0}, _year{0}
{}
Date::Date(const char* s)
	: Date()
{
	// assuming DD-MM-YYYY:
	_day = 10 * (s[0] - 48) + s[1] - 48;
	_month = 10 * (s[3] - 48) + s[4] - 48;
	_year = 1000 * (s[6] - 48) + 100 * (s[7] - 48);
	_year += 10 * (s[8] - 48) + (s[9] - 48);
}

uint16_t& Date::day()
{
	return _day;
}

const uint16_t& Date::day() const
{
	return _day;
}

uint16_t& Date::month()
{
	return _month;
}

const uint16_t& Date::month() const {
	return _month;
}

uint16_t& Date::year() {
	return _year;
}

const uint16_t& Date::year() const {
	return _year;
}

bool Date::isEqual(const Date& date) {
	return _day == date.day() && _month == date.month() && _year == date.year();
}

bool Date::isBefore(const Date& date)
{
	if (isEqual(date)) {
		return false;
	}
	if (_year < date.year()) {
		return true;
	} else {
		if (_month < date.month()) {
			return true;
		} else {
			if (_day < date.day()) {
				return true;
			}
		}
	}
	return false;
}

uint16_t Date::getDay() const {
	return _day;
}

void Date::setDay(uint16_t day) {
	_day = day;
}

uint16_t Date::getMonth() const
{
	return _month;
}

void Date::setMonth(uint16_t month)
{
	_month = month;
}

uint16_t Date::getYear() const
{
	return _year;
}

void Date::setYear(uint16_t year)
{
	_year = year;
}