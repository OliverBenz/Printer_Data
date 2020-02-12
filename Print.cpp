#include "Print.hpp"

Print::Print() {
	id = 0; roll = 0; count = 0;
	length = 0.0f; weight = 0.0f; price = 0.0f;
	user = ""; projectName = ""; notes = ""; status = ""; printName = "";

	date = Date(); dateUntil = Date(); datePlanned = Date(); dateDone = Date();
	time = Time(); timeReal = Time();
}

Print::Print(int id, int roll, int count, float length, float weight, float price) {
	this->id = id;
	this->roll = roll;
	this->count = count;
	this->length = length;
	this->weight = weight;
	this->price = price;
}

void Print::setInfo(std::string user, std::string projectName, std::string notes, std::string status, std::string printName) {
	this->user = user;
	this->projectName = projectName;
	this->notes = notes;
	this->status = status;
	this->printName = printName;
};

void Print::setDate(const Date& date, const Date& dateUntil, const Date& datePlanned, const Date& dateDone) {
	this->date = date;
	this->dateUntil = dateUntil;
	this->datePlanned = datePlanned;
	this->dateDone = dateDone;
}

void Print::setTime(Time time, Time timeReal) {
	this->time = time;
	this->timeReal = timeReal;
}

Time Print::getTimeDiff() {
	if (timeReal.hours != 0 && timeReal.minutes != 0) {
		Time t(time.hours - timeReal.hours, time.minutes - timeReal.minutes, time.seconds - timeReal.seconds);
		return t;
	}
	
	return Time();
}

std::ostream& operator <<(std::ostream& os, Print p) {
	os << "------------------------------" << std::endl;
	os << p.id << " - " << p.user << ": " << p.printName << " - " << p.status << std::endl;
	os << "Time: " << p.time << "  Length: " << p.length << "  Weight: " << p.weight << "  Price: " << p.price << std::endl;
	os << "Roll: " << p.roll << "  Count: " << p.count << std::endl;

	os << "Date: " << p.date << "  Duedate: " << p.dateUntil << "  Planned: " << p.datePlanned;
	if (p.status == "Done") os << "  Done: " << p.dateDone << std::endl;
	else os << std::endl;

	return os;
}