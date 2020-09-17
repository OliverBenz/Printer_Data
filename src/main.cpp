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

using namespace std;
using namespace Printer::Data;

// Analytic functions
void mostPrints(vector<Print>& prints);

int main() {
	ifstream file("res/prints.csv");

	vector<Print> prints;

	if (! file.is_open()){
		cout << "Could not open file" << endl;
		return -1;
	}

	string line;
	while (getline(file, line))
		prints.push_back(Print(line));
	file.close();

	cout << "Person with the most prints: ";
	mostPrints(prints);

	cout << prints[17] << endl;

	return 0;
}

void mostPrints(vector<Print>& prints) {
	map<string, int> userPrints;
	
	// Insert users and printCount to map
	for (auto& i : prints) {
		if (userPrints.find(i.getUser()) != userPrints.end())
			userPrints.find(i.getUser())->second += 1;
		else {
			userPrints.insert(make_pair(i.getUser(), 1));
		}
	}

	// Get pair with most prints from map
	pair<string, int> most = *userPrints.begin();
	for (auto& i : userPrints)
		if (i.second > most.second)
			most = i;

	cout << most.first << " - " << most.second << endl;
}

