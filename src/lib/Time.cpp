#include "Time.hpp"

namespace Printer {
namespace Data {

Time::Time() {
	hours = -1;
	minutes = -1;
	seconds = -1;
}

Time::Time(int hours, int minutes, int seconds) {
	this->hours = hours;
	this->minutes = minutes;
	this->seconds = seconds;
}

Time::Time(std::string t) {
	this->hours = -1;
	this->minutes = -1;
	this->seconds = -1;

	std::string val = "";
	for (size_t i = 0; i < t.size(); i++) {
		if (t[i] == 'h') {
			this->hours = stoi(val);
			val = "";
		}
		else if (t[i] == 'm') {
			this->minutes = stoi(val);
		}
		else if (t[i] == 's') {
			this->seconds = stoi(val);
			break;
		}
		else val += t[i];
	}
}

std::ostream& operator << (std::ostream& os, Time& t) {
	if(t.hours == -1) return (os << "Nan");
	os << t.hours;

	if(t.minutes == -1) return os;
	os << ":" << t.minutes;

	if(t.seconds == -1) return os;
	os << ":" << t.seconds;
	
	return os;
}

}
}