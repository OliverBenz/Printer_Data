#pragma once

#include <ostream>
#include <string>

class Date{
public:
	int day, month, year;

public:
	Date();
	Date(int day, int month, int year);
	Date(std::string d);

	friend std::ostream& operator << (std::ostream& os, Date& d);
	friend bool operator == (Date& d1, Date& d2);
	friend bool operator != (Date& d1, Date& d2);
	friend bool operator < (Date& d1, Date& d2);
	friend bool operator > (Date& d1, Date& d2);
	friend bool operator <= (Date& d1, Date& d2);
	friend bool operator >= (Date& d1, Date& d2);
};