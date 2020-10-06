#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>

#include "lib/Date.hpp"
#include "lib/Time.hpp"
#include "lib/Print.hpp"

using namespace Printer::Data;

// Analytic functions
void mostPrints(std::vector<Print>& prints);

int main() {
	std::ifstream file("res/prints.csv");

	std::vector<Print> prints;

	if (! file.is_open()){
		std::cout << "Could not open file.\n";
		return -1;
	}

	std::string line;
	while (std::getline(file, line))
		prints.push_back(Print(line));
	file.close();

	std::cout << "Person with the most prints: ";
	mostPrints(prints);

	std::cout << prints[17] << std::endl;

	return 0;
}

void mostPrints(std::vector<Print>& prints) {
	std::map<std::string, int> userPrints;
	
	// Insert users and printCount to map
	for (auto& i : prints) {
		if (userPrints.find(i.getUser()) != userPrints.end())
			userPrints.find(i.getUser())->second += 1;
		else
			userPrints.insert(make_pair(i.getUser(), 1));
	}

	// Get pair with most prints from map
	std::pair<std::string, int> most = *userPrints.begin();
	for (auto& i : userPrints)
		if (i.second > most.second)
			most = i;

	std::cout << most.first << " - " << most.second << "\n";
}

