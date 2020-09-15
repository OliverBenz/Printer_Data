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

	bool exists();

	friend std::ostream& operator << (std::ostream& os, Date& d);
	friend bool operator == (Date& left, Date& right);
	friend bool operator != (Date& left, Date& right);
	friend bool operator < (Date& left, Date& right);
	friend bool operator > (Date& left, Date& right);
	friend bool operator <= (Date& left, Date& right);
	friend bool operator >= (Date& left, Date& right);
};