// Group 1 - Creating the perfect file
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

const int MAX = 100;
const int COLS = 14;

string master[COLS][MAX];

const string ORDER[COLS] = {"CRN", "PREF","CRS", "TITLE", "CR", "DAYS", "ST TM", "END TM", "ROOM", "CAP", "ST DT", "END DT", "LST NM", "FST NM"};

int indexes[COLS]; // This would be the index of each "important" column in the file being read in

int getHeader(int index) {
	for (int i = 0; i < COLS; i++) {
		if (indexes[i] == index) {
			return i;
		}
	}
	return -1; // oops something went wrong
}

bool containsNewLine(string s) {
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '\n') {
			return true;
		}
	}
	return false;
}
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
        return "NONE";
    }

    // Check if length is correct
    if (time.length() != 6) {
        cout << "Time format is incorrect: " << time << endl;
        return "NONE";
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
	//printMaster(); // This should be empty

	//---------------------------------READ RAW DATA FROM FILE-----------------------------------
	ifstream fin;
	fin.open("psy.csv");

	if (!fin) {
		cout << "Unable to open file" << endl;
	}

	//---------------------------------DETERMINE INDEXES----------------------------
	// Indexes are determined to make sure every file is not missing any rows, and every column
	// 		is in the right order

	string headers[100];
	string cell;
	int i = 0;


	// gets headers
	while (!containsNewLine(cell)) {
		cout << "b" << endl;
		getline(fin, cell, ',');
		headers[i] = cell;
		i++;
	}
	fin.close();


	// initialize index
	for (int i = 0; i < COLS; i++) {
		indexes[i] = 99; // 99 = error
	}
	// gets indexes
	for (int i = 0; i < 100; i++) {
		string header = headers[i];

		// compare to ORDER
		for (int j = 0; j < COLS; j++) {
			if (header == ORDER[j]) {
				indexes[j] = i; // sorry if this is confusing
			}
		}
	}

	// diagnostics - alert user if headers are missing
	for (int i = 0; i < COLS; i++) {
		int index = indexes[i];
		//cout << index << endl;
		if (index == 99) {
			cout << "Header '" << ORDER[i] << "' is missing. Make sure to rename it to the correct header name" << endl;
		}
	}

	//! FIXME: seg fault here :(
	//---------------------------Fill 2D array-------------------------------
	ifstream fin2;
	fin2.open("psy.csv");
	getline(fin2, cell); // get the headers over with
	int row = 0, col = 0;
	while (col < 50) {
		getline(fin2, cell, ',');
		if (containsNewLine(cell)) {
			row++;
			col = 0;
			cell.erase(0, 1); // delete the first character (in this case \n)
		}
		// cout << "Row: " << row << " Col: " << col << " Header: " << getHeader(indexes[col]) << " | " << cell << endl;

		//deal with cell here
		if (getHeader(col) != -1) {
			master[getHeader(col)][row] = cell;
		}

		col++;

	}

	fin2.close();

	//------------------------------------Almost Done! change tiomes to military time-----------------------
	for (int i = 0; i < MAX; i++) {
		master[STARTTIME][i] = toMilitary(master[STARTTIME][i]);
		master[ENDTIME][i] = toMilitary(master[ENDTIME][i]);
	}


	//---------------------------------Last Step(?) - write to master file------------------------
	ofstream fout;
	printMaster();

    return 0;
}
