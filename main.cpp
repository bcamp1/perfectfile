#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

// convert time to military time
string toMilitary(string time) {
    string newTime; // We will return this

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

    string numberstr = time.substr(0, 4); // example 0150
    string suffix = time.substr(4, 2);  // example PM

    int numbers = stoi(numberstr);

    if (suffix == "am" || suffix == "AM") {
        return to_string(numbers-1200);
    } else {
        return to_string(numbers);
    }

    return newTime;
}

int main() {
        string crnArray [500];
        string prefArray [500];
        string crsArray [500];
        string titleArray [500];
        string crArray [500];
        string daysArray [500];
        string startTimeArray [500];
        string endTimeArray [500];
        string room [500];
        string cap [500];
        string startDate [500];
        string endDate [500];
        string lastName [500];
        string firstName [500];
        string courseNotes [500];

    return 0;
}
