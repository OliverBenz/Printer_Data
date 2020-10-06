#pragma once

#include <string>
#include <ostream>
#include "Date.hpp"
#include "Time.hpp"

namespace Printer {
namespace Data {

class Print{
	int id, roll, count;
	float length, weight, price;

	std::string user, projectName, notes, status, printName;

	Date date, dateUntil, datePlanned, dateDone;
	Time time, timeReal;

public:
	Print();
	Print(int id, int roll, int count, float length, float weight, float price);
	Print(std::string print);

	[[nodiscard]] Time getTimeDiff();
	[[nodiscard]] std::string getUser();
	[[nodiscard]] std::string getPrintName();

	friend std::ostream& operator <<(std::ostream& os, Print p);
};

}
}