#pragma once

#include <string>
#include <ostream>
#include "Date.hpp"
#include "Time.hpp"

class Print{
	int id, roll, count;
	float length, weight, price;

	std::string user, projectName, notes, status, printName;

	Date date, dateUntil, datePlanned, dateDone;
	Time time, timeReal;

public:
	Print();

	Print(int id, int roll, int count, float length, float weight, float price);

	void setInfo(std::string user, std::string projectName, std::string notes, std::string status, std::string printName);
	void setDate(const Date& date, const Date& dateUntil, const Date& datePlanned, const Date& dateDone);
	void setTime(Time time, Time timeReal);

	Time getTimeDiff();

	friend std::ostream& operator <<(std::ostream& os, Print p);
};

