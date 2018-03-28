#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

const int crn = 0;
const int pref = 1;
const int crs = 2;
const int title = 3;
const int cr = 4;
const int days = 5;
const int startTime = 6;
const int endTime = 7;
const int room = 8;
const int cap = 9;
const int startDate = 10;
const int endDate = 11;
const int lastName = 12;
const int firstName = 13;
const int courseNotes = 14;

string master[15][500];

// convert time to military time
string toMilitary(string time) {
    // -------------Checks--------------

    // Check if TBA
    if (time == "TBA") {
        return "0";
    }

    // Check if length is correct
    if (time.length() != 6) {
        cout << "Time format is incorrect: " << time << endl;
        return "0";
    }

	//-------------Conversion-------------
    string numberstr = time.substr(0, 4); // example 0150
    string suffix = time.substr(4, 2);  // example PM

	int numbers = stoi(numberstr);

    if (suffix == "am" || suffix == "AM") {
    	if (numbers >= 1200) {
			return to_string(numbers-1200);
		} else {
			return to_string(numbers);
		}
    } else if (suffix == "pm" || suffix == "PM") {
		if (numbers >= 1200) {
			return to_string(numbers);
		} else {
			return to_string(numbers+1200);
		}
        return to_string(numbers);
    }
	cout << suffix << endl;
	return "ERROR";
}

int main() {
	cout << toMilitary("0230AM") << endl;
	cout << toMilitary("0230PM") << endl;
	cout << toMilitary("1230AM") << endl;
	cout << toMilitary("0930PM") << endl;
	cout << toMilitary("0230AM") << endl;
	cout << toMilitary("0230AM") << endl;
    return 0;
}
