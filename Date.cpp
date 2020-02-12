#include "Date.hpp"

Date::Date() {
	day = 0;
	month = 0;
	year = 0;
}

Date::Date(int day, int month, int year) {
	this->day = day;
	this->month = month;
	this->year = year;
}

std::ostream& operator << (std::ostream& os, Date& d) {
	return (os << d.day << "." << d.month << "." << d.year);
}