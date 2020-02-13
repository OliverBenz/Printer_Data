#pragma once

#include <ostream>
class Time{
public:
	int hours, minutes, seconds;

	Time();
	Time(int hours, int minutes, int seconds);

	friend std::ostream& operator << (std::ostream& os, Time& t);
};