#pragma once

#include <ostream>
class Date{
public:
	int day, month, year;

public:
	Date();
	Date(int day, int month, int year);

	friend std::ostream& operator << (std::ostream& os, Date& d);
};