#include "Time.hpp"

Time::Time() {
	hours = 0;
	minutes = 0;
	seconds = 0;
}

Time::Time(int hours, int minutes, int seconds) {
	this->hours = hours;
	this->minutes = minutes;
	this->seconds = seconds;
}

 std::ostream& operator << (std::ostream& os, Time& t) {
	return (os << t.hours << "h " << t.minutes << "m " << t.seconds << "s");
}