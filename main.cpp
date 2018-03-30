#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
using namespace std;

const int CRN = 0;
const int PREF = 1;
const int CRS = 2;
const int TITLE = 3;
const int CR = 4;
const int DAYS = 5;
const int STARTTIME = 6;
const int ENDTIME = 7;
const int ROOM = 8;
const int CAP = 9;
const int STARTDATE = 10;
const int ENDDATE = 11;
const int LASTNAME = 12;
const int FIRSTNAME = 13;
const int COURSENOTES = 14;

const int MAX = 100;
const int COLS = 15;

string master[COLS][MAX];

const string ORDER[COLS] = {"CRN", "PREF","CRS", "TITLE", "CR", "DAYS", "STARTTIME", "ENDTIME", "ROOM", "CAP", "STARTDATE", "ENDDATE", "LASTNAME", "FIRSTNAME", "COURSENOTES"};

int indexes[COLS]; // This would be the index of each "important" column in the file being read in

// printMaster prints the master array out
void printMaster() {
	for (int col = 0; col < COLS; col++) {
		cout << "=====" << ORDER[col] << "=====" << endl;
		for (int row = 0; row < MAX; row++) {
			if (master[col][row] != "NONE") {
				cout << master[col][row] << endl;
			}
		}
		cout << endl << endl; // for formatting
	}
}

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
	// initialize array elements
	for (int i = 0; i < COLS; i++) {
		for (int j = 0; j < MAX; j++) {
			master[i][j] = "NONE"; // Initialize with NONE so we will know if something is wrong
		}
	}

	printMaster(); // This should be empty

	//---------------------------------READ RAW DATA FROM FILE-----------------------------------
	ifstream fin;
	fin.open("psy.csv")

	if (!fin) {
		cout << "Unable to open file" << endl;
	}

	// Get each cell
	string cell;

	while (fin >> cell) {
		// Do the stuff
		
	}

    return 0;
}
