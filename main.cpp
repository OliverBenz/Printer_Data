#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

#include "Date.hpp"
#include "Time.hpp"
#include "Print.hpp"

using namespace std;

Print getPrint(string line);
Time getTime(string t);
Date getDate(string d);

//void abweichung(vector<Print>* prints);

int main() {
	ifstream file("all.csv");

	vector<Print> prints;

	if (file.is_open()) {
		string line;
		while (getline(file, line))
			prints.push_back(getPrint(line));
	}
	else cout << "Could not open file" << endl;

	if(!prints.empty()) cout << prints.back() << endl;

	file.close();
	return 0;
}


// Formatting functions
Print getPrint(string line) {
	stringstream ssLine(line);

	vector<string> values;
	string temp;
	while (getline(ssLine, temp, '@')) values.push_back(temp);

	// Replace ',' in float values with '.'
	for (size_t i = 13; i <= 15; i++) replace(values[i].begin(), values[i].end(), ',', '.');

	Print test(stoi(values[0]), stoi(values[1]), stoi(values[2]), stof(values[13]), stof(values[14]), stof(values[15]));
	test.setTime(getTime(values[12]), getTime(values[16]));
	test.setInfo(values[3], values[8], values[9], values[10], values[11]);
	test.setDate(getDate(values[4]), getDate(values[5]), getDate(values[6]), getDate(values[7]));

	return test;
};

Time getTime(string t) {
	if (t == "") return Time();
	Time time;

	string val = "";
	for (size_t i = 0; i < t.size(); i++) {
		if (t[i] == 'h') {
			time.hours = stoi(val);
			val = "";
		}
		else if (t[i] == 'm') {
			time.minutes = stoi(val);
			break;
		}
		else val += t[i];
	}

	return time;
}

Date getDate(string d) {
	if(d == "") return Date();
	stringstream ss(d);
	
	vector<string> vals;
	string temp;
	while (getline(ss, temp, '.')) vals.push_back(temp);

	Date date(stoi(vals[0]), stoi(vals[1]), stoi(vals[2]));

	return date;
}